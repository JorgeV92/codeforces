package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func kawaiiness(adj [][]int, k int) int64 {
	n := len(adj)
	parent := make([]int, n)
	parent[0] = -1
	order := make([]int, 1, n)
	for i := 0; i < len(order); i++ {
		v := order[i]
		for _, u := range adj[v] {
			if u != parent[v] {
				parent[u] = v
				order = append(order, u)
			}
		}
	}
	answer := int64(n)
	size := make([]int, n)
	for i := n - 1; i > 0; i-- {
		v := order[i]
		size[v]++
		s := size[v]
		if s >= k {
			answer += int64(n - s)
		}
		if n-s >= k {
			answer += int64(s)
		}
		size[parent[v]] += s
	}
	return answer
}

func main() {
	data, _ := io.ReadAll(os.Stdin)
	pos := 0
	nextInt := func() int {
		for pos < len(data) && data[pos] <= ' ' {
			pos++
		}
		x := 0
		for pos < len(data) && data[pos] >= '0' && data[pos] <= '9' {
			x = x*10 + int(data[pos]-'0')
			pos++
		}
		return x
	}
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	for t := nextInt(); t > 0; t-- {
		n, k := nextInt(), nextInt()
		adj := make([][]int, n)
		for i := 0; i < n-1; i++ {
			u, v := nextInt()-1, nextInt()-1
			adj[u] = append(adj[u], v)
			adj[v] = append(adj[v], u)
		}
		fmt.Fprintln(out, kawaiiness(adj, k))
	}
}
