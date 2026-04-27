package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
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
		A := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &A[i])
		}
		slices.Reverse(A)
		cnt := 0
		for i := 0; i < n; {
			if A[i] == A[0] {
				i++
			} else {
				i *= 2
				cnt++
			}
		}
		fmt.Fprintln(out, cnt)
	}
}
