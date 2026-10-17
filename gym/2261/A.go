package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

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
		n := nextInt()
		s := nextString()
		count, first, last := 0, -1, -1
		for i := 0; i < n; i++ {
			if s[i] == '1' {
				count++
				if first == -1 {
					first = i
				}
				last = i
			}
		}

		answer := count - 1
		if count >= 3 {
			answer = last - first
		}
		fmt.Fprintln(out, answer)
	}
}
