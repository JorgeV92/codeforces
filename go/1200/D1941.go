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
		fmt.Fscan(in, &n)
		a := make([]int, n)
		b := make([]int, n)
		c := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
		}
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &b[i])
		}
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &c[i])
		}
		pa := make([]int, n)
		pb := make([]int, n)
		pc := make([]int, n)
		for i := 0; i < n; i++ {
			pa[i] = i
			pb[i] = i
			pc[i] = i
		}

		sort.Slice(pa, func(i, j int) bool { return a[pa[i]] > a[pa[j]] })
		sort.Slice(pb, func(i, j int) bool { return b[pb[i]] > b[pb[j]] })
		sort.Slice(pc, func(i, j int) bool { return c[pc[i]] > c[pc[j]] })

		ans := 0
		for i := 0; i < 3; i++ {
			for j := 0; j < 3; j++ {
				for k := 0; k < 3; k++ {
					x := pa[i]
					y := pb[j]
					z := pc[k]
					if x != y && y != z && x != z {
						ans = max(ans, a[x]+b[y]+c[z])
					}
				}
			}
		}
		fmt.Fprintln(out, ans)
	}
}
