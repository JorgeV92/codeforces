package main

import (
	"bufio"
	"fmt"
	"os"
)

func gcd(a, b int64) int64 {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	a := make([]int64, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	for c := 0; c < 2; c++ {
		var g int64 = 0
		for i := c; i < n; i += 2 {
			g = gcd(g, a[i])
		}
		ok := true
		for i := 1 - c; i < n; i += 2 {
			if a[i]%g == 0 {
				ok = false
				break
			}
		}
		if ok {
			fmt.Fprintln(out, g)
			return
		}
	}
	fmt.Fprintln(out, 0)
}

func main() {
	in := bufio.NewReaderSize(os.Stdin, 1<<20)
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	var T int
	fmt.Fscan(in, &T)
	for T > 0 {
		solve(in, out)
		T--
	}
}
