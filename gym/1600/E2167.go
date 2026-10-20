package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func teleportPositions(a []int, k, x int) []int {
	sort.Ints(a)
	n := len(a)
	canPlace := func(d int) bool {
		count := 0
		if a[0] >= d {
			count += a[0] - d + 1
		}
		for i := 1; i < n; i++ {
			if length := a[i] - a[i-1] - 2*d + 1; length > 0 {
				count += length
			}
		}
		if x-a[n-1] >= d {
			count += x - a[n-1] - d + 1
		}
		return count >= k
	}

	low, high := 0, x+1
	for high-low > 1 {
		mid := low + (high-low)/2
		if canPlace(mid) {
			low = mid
		} else {
			high = mid
		}
	}

	positions := make([]int, 0, k)
	if low == 0 {
		for p := 0; p < k; p++ {
			positions = append(positions, p)
		}
		return positions
	}

	addInterval := func(left, right int) {
		for p := left; p <= right && len(positions) < k; p++ {
			positions = append(positions, p)
		}
	}
	addInterval(0, a[0]-low)
	for i := 1; i < n && len(positions) < k; i++ {
		addInterval(a[i-1]+low, a[i]-low)
	}
	addInterval(a[n-1]+low, x)
	return positions
}

func main() {
	data, _ := io.ReadAll(os.Stdin)
	pos := 0
	nextInt := func() int {
		for pos < len(data) && data[pos] <= ' ' {
			pos++
		}
		x := 0
		for pos < len(data) && data[pos] >= '0' && data[pos] <= '9' {
			x = x*10 + int(data[pos]-'0')
			pos++
		}
		return x
	}
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	for t := nextInt(); t > 0; t-- {
		n, k, x := nextInt(), nextInt(), nextInt()
		a := make([]int, n)
		for i := range a {
			a[i] = nextInt()
		}
		positions := teleportPositions(a, k, x)
		for i, p := range positions {
			if i > 0 {
				fmt.Fprint(out, " ")
			}
			fmt.Fprint(out, p)
		}
		fmt.Fprintln(out)
	}
}
