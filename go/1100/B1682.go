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
		p := make([]int, n)
		ans := -1
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &p[i])
			if p[i] != i {
				ans &= i
			}
		}
		fmt.Fprintln(out, ans)
	}
}
