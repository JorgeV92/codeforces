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
		var z int 
		fmt.Fscan(in, &n,&z)

		ans := 0
		for i := 0; i < n; i++ {
			var x int
			fmt.Fscan(in, &x)
			ans = max(ans, x | z)
		}

		fmt.Fprintln(out, ans)
	}
	
}
