package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func maximumScore(s string, k int) int {
	pairs := len(s) / 2
	path := make([]int, 0, pairs)
	closed, answer := 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] == ')' {
			path = path[:len(path)-1]
			closed++
			continue
		}

		path = append(path, closed)
		depth := len(path)
		start := sort.SearchInts(path, closed-k)
		if length := depth - start; length > answer {
			answer = length
		}

		if closed <= k {
			length := depth + k
			if length > pairs {
				length = pairs
			}
			if length > answer {
				answer = length
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
	nextString := func() string {
		for pos < len(data) && data[pos] <= ' ' {
			pos++
		}
		start := pos
		for pos < len(data) && data[pos] > ' ' {
			pos++
		}
		return string(data[start:pos])
	}
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	t := nextInt()
	for ; t > 0; t-- {
		_ = nextInt()
		k := nextInt()
		s := nextString()
		fmt.Fprintln(out, maximumScore(s, k))
	}
}
