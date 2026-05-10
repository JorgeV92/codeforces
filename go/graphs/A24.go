package main

import (
	"bufio"
	"fmt"
	"os"
)

type Edge struct {
	to   int
	cost int
}

func main() {
	in := bufio.NewReaderSize(os.Stdin, 1<<20)
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	var n int
	fmt.Fscan(in, &n)

	adj := make([][]Edge, n)

	for i := 0; i < n; i++ {
		var a, b, c int
		fmt.Fscan(in, &a, &b, &c)
		a--
		b--
		adj[a] = append(adj[a], Edge{to: b, cost: 0})
		adj[b] = append(adj[b], Edge{to: a, cost: c})
	}
	ans := 1_000_000_000
	for _, e := range adj[0] {
		x := 0
		sum := 0
		y := e.to

		for i := 0; i < n; i++ {
			for _, ed := range adj[x] {
				if ed.to != y {
					y = ed.to
					sum += ed.cost
					break
				}
			}
			x, y = y, x
		}
		ans = min(ans, sum)
	}
	fmt.Fprintln(out, ans)
}
