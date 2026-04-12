package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReaderSize(os.Stdin, 1<<20)
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for t > 0 {
		t--
		var n, l, r int
		fmt.Fscan(in, &n, &l, &r)
		a := make([]int, n+1)
		ok := true
		for i := 1; i <= n; i++ {
			a[i] = ((l-1)/i + 1) * i
			ok = ok && a[i] <= r
		}
		if ok {
			fmt.Fprintln(out, "YES")
			for i := 1; i <= n; i++ {
				fmt.Fprint(out, a[i])
				fmt.Fprint(out, " ")
			}
			fmt.Fprintln(out)
		} else {
			fmt.Fprintln(out, "NO")
		}
	}
}
