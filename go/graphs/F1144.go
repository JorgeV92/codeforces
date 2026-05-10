package main

import (
	"bufio"
	"fmt"
	"os"
)

type Edge struct {
	u int
	v int
}

func main() {
	in := bufio.NewReaderSize(os.Stdin, 1<<20)
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	var n, m int
	fmt.Fscan(in, &n, &m)

	adj := make([][]int, n)
	e := make([]Edge, 0, n)

	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscan(in, &u, &v)
		u--
		v--
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
		e = append(e, Edge{u, v})
	}

	vis := make([]int, n)
	for i := 0; i < n; i++ {
		vis[i] = -1
	}

	is_bipartite := true
	q := make([]int, 0)

	for st := 0; st < n; st++ {
		if vis[st] == -1 {
			vis[st] = 0
			q = append(q, st)
			for len(q) > 0 {
				x := q[0]
				q = q[1:]
				for _, y := range adj[x] {
					if vis[y] == -1 {
						vis[y] = vis[x] ^ 1
						q = append(q, y)
					} else if vis[y] == vis[x] {
						is_bipartite = false
					}
				}
			}
		}
	}

	if is_bipartite {
		fmt.Fprintln(out, "YES")
		for _, ee := range e {
			if vis[ee.u] == 0 {
				fmt.Fprint(out, "0")
			} else {
				fmt.Fprint(out, "1")
			}
		}
		fmt.Fprintln(out)
	} else {
		fmt.Fprintln(out, "NO")
	}
}
