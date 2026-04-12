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
		w := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &w[i])
		}
		ans := 0
		var A int64 = 0
		var B int64 = 0
		for i, j := 0, n-1; i < n; i++ {
			A += int64(w[i])
			for A > B {
				B += int64(w[j])
				j--
			}
			if A == B && i <= j {
				ans = max(ans, i+n-j)
			}
		}
		fmt.Fprintln(out, ans)
	}
}
