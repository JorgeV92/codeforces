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

func main() {
	in := bufio.NewReaderSize(os.Stdin, 1<<20)
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	var T int
	fmt.Fscan(in, &T)

	for T > 0 {
		T--

		var n int
		fmt.Fscan(in, &n)

		a := make([]int64, n)
		var sum int64 = 0
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
			sum += a[i]
		}

		var pref int64 = 0
		var ans int64 = 1

		for i := 0; i < n-1; i++ {
			pref += a[i]
			g := gcd(sum, pref)
			if g > ans {
				ans = g
			}
		}

		fmt.Fprintln(out, ans)
	}
}
