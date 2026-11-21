package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var n, m int 
	fmt.Fscan(in, &n, &m) 


	h := make([]int, n)
	for i := range h {
		fmt.Fscan(in, &h[i]) 
	}	
	size := 1 
	for size < n {
		size <<= 1
	}
	seg := make([]int, 2*size)
	for i := 0; i < n; i++ {
		seg[size+i] = h[i]
	}
	for i := 0; i < m; i++ {
		var x int 
		fmt.Fscan(in, &x)
		if seg[1] < x {
			fmt.Fprint(out, 0, " ")
			continue
		}
		node := 1 
		for node < size {
			if seg[node<<1] >= 1 {
				node = node<<1
			} else {
				node = node<<1|1
			}
		}
		hh := node - size 
		fmt.Fprint(out, hh+1, " ")
		seg[node] -= x 
		node >>= 1
		for node > 0 { 
			seg[node] = max(seg[node<<1], seg[node<<1|1])
		}
	}
	fmt.Fprint(out)
}
