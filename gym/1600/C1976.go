package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func solve(n, m int, a, b []int) []int64 {
	answer := make([]int64, len(a))
	role := make([]int, len(a))
	skills := [2][]int{a, b}
	for extra := 0; extra < 2; extra++ {
		capacity := [2]int{n, m}
		capacity[extra]++
		used := [2]int{}
		var total int64
		for i := range a {
			r := 0
			if b[i] > a[i] {
				r = 1
			}
			if used[r] == capacity[r] {
				r ^= 1
			}
			role[i] = r
			used[r]++
			total += int64(skills[r][i])
		}
		for i, r := range role {
			if r == extra {
				answer[i] = total - int64(skills[r][i])
			}
		}
	}
	return answer
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
		n, m := nextInt(), nextInt()
		a := make([]int, n+m+1)
		b := make([]int, n+m+1)
		for i := range a {
			a[i] = nextInt()
		}
		for i := range b {
			b[i] = nextInt()
		}
		for i, score := range solve(n, m, a, b) {
			if i > 0 {
				fmt.Fprint(out, " ")
			}
			fmt.Fprint(out, score)
		}
		fmt.Fprintln(out)
	}
}
