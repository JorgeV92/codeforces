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
		var k int64
		fmt.Fscan(in, &k)
		var lo int64 = 0
		var hi int64 = 2_000_000_000

		for lo < hi {
			mid := lo + (hi-lo)/2
			if mid*(mid+1) >= k {
				hi = mid
			} else {
				lo = mid + 1
			}
		}
		fmt.Fprintln(out, k+lo)
	}

}
