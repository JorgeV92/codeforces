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

	var T int
	fmt.Fscan(in, &T)

	for T > 0 {
		T--
		var n int
		fmt.Fscan(in, &n)
		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
			a[i]--
		}
		i := 0
		for i < n && a[i] == a[n-i-1] {
			i++
		}
		if i == n {
			fmt.Fprintln(out, "YES")
			continue
		}
		ok := false
		for _, x := range []int{a[i], a[n-i-1]} {
			b := make([]int, 0, n)
			for _, v := range a {
				if v != x {
					b = append(b, v)
				}
			}
			good := true
			for l, r := 0, len(b)-1; l < r; l, r = l+1, r-1 {
				if b[l] != b[r] {
					good = false
					break
				}
			}
			if good {
				ok = true
				break
			}
		}
		if ok {
			fmt.Fprintln(out, "YES")
		} else {
			fmt.Fprintln(out, "NO")
		}
	}
}
