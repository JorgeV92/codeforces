package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
		var k int64
		fmt.Fscan(in, &n, &k)
		A := make([]int64, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &A[i])
		}
		sort.Slice(A, func(i, j int) bool { return A[i] < A[j] })
		ok := false
		j := 0
		for i := 0; i < n; i++ {
			for j < n && A[j] < A[i]+k {
				j++
			}
			if j < n && A[j] == A[i]+k {
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
