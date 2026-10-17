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
		odd := 0
		for i := 0; i < n; i++ {
			if nextInt()%2 == 1 {
				odd++
			}
		}
		if (n == 2 && odd == 1) || (n == 3 && odd == 3) {
			fmt.Fprintln(out, "Larpity")
		} else {
			fmt.Fprintln(out, "Moggity")
		}
	}
}
