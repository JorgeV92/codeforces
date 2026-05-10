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

	for ; T > 0; T-- {
		var N, M int
		fmt.Fscan(in, &N, &M)
		adj := make([][]int, N)

		for i := 0; i < M; i++ {
			var u, v int
			fmt.Fscan(in, &v, &u)
			u--
			v--
			adj[u] = append(adj[u], v)
			adj[v] = append(adj[v], u)
		}
		ans := 0
		side := make([]int, N)
		for i := 0; i < N; i++ {
			side[i] = -1
		}
		for st := 0; st < N; st++ {
			if side[st] == -1 {
				q := []int{}
				q = append(q, st)
				side[st] = 0
				is_bipartite := true
				cnt := [2]int{}
				for len(q) > 0 {
					v := q[0]
					q = q[1:]
					cnt[side[v]]++
					for _, u := range adj[v] {
						if side[u] == -1 {
							side[u] = side[v] ^ 1
							q = append(q, u)
						} else {
							if side[u] == side[v] {
								is_bipartite = false
							}
						}
					}
				}
				if is_bipartite {
					ans += max(cnt[0], cnt[1])
				}
			}
		}
		fmt.Fprintln(out, ans)
	}
}
