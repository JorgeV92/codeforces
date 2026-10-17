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
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	t := nextInt()
	for ; t > 0; t-- {
		n := nextInt()
		minimum := nextInt()
		maximum := minimum
		for i := 1; i < n; i++ {
			x := nextInt()
			if x < minimum {
				minimum = x
			}
			if x > maximum {
				maximum = x
			}
		}
		mask := 0
		for diff := minimum ^ maximum; diff > 0; diff >>= 1 {
			mask = (mask << 1) | 1
		}
		fmt.Fprintln(out, maximum|mask)
	}
}
