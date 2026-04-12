package main

import (
	"bufio"
	"fmt"
	"os"
)

func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func main() {
	in := bufio.NewReaderSize(os.Stdin, 1<<20)
	out := bufio.NewWriterSize(os.Stdout, 1<<20)
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)

	for t > 0 {
		t--
		var n int
		fmt.Fscan(in, &n)
		pos := make([]int, 1001)
		for i := range pos {
			pos[i] = 0
		}
		for i := 1; i <= n; i++ {
			var x int
			fmt.Fscan(in, &x)
			pos[x] = i
		}
		ans := -1
		for x := 1; x <= 1000; x++ {
			for y := 1; y <= 1000; y++ {
				if pos[x] > 0 && pos[y] > 0 && gcd(x, y) == 1 {
					ans = max(ans, pos[x]+pos[y])
				}
			}
		}
		fmt.Fprintln(out, ans)
	}
}
