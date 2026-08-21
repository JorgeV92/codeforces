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

	var t int 
	fmt.Fscan(in, &t)

	for tt := 0; tt < t; tt++ { 
		var n int 
		fmt.Fscan(in, &n)

		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(in, &a[i])
		}
		
		if n == 1 {
			fmt.Fprintln(out, 0)
			continue
		}

		ans := -1

		for z := 0; z < 2; z++ {
			if z == 1 {
				for i, j := 0, len(a)-1; i < j; i, j = i+1, j-1 {
					a[i], a[j] = a[j], a[i]
				}
			}

			prv := -1 
			mn := a[0]
			mx := a[0]

			for i := 1; i < n; i++ {
				if a[i] > mx {
					mx = a[i]
					if prv != 0 {
						ans++
						prv = 0
					}
				} else if a[i] < mn {
					mn = a[i]
					if prv != 1 {
						ans++
						prv = 1
					}
				}
			}
		}

		fmt.Fprintln(out, ans)
	}
}
