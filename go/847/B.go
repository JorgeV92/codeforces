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

	var n int
	fmt.Fscan(in, &n)

	res := make([][]int, 0)
	last := make([]int, 0)

	for i := 0; i < n; i++ {
		var x int
		fmt.Fscan(in, &x)
		lo, hi := 0, len(last)
		for lo < hi {
			mid := lo + (hi-lo) / 2
			if last[mid] < x {
				hi = mid
			} else {
				lo = mid + 1
			}
		}

		if lo == len(last) {
			last = append(last, x)
			res = append(res, []int{x})
		} else {
			last[lo] = x
			res[lo] = append(res[lo], x)
		}
	}

	for _, seq := range res {
		for _, s := range seq  {
			fmt.Fprint(out, s, " ")
		}
		fmt.Fprintln(out)
	}
}
