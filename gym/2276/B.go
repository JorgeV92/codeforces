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
	for ; t > 0; t-- {
		var s string
		fmt.Fscan(in, &s)
		canIncrease, canDecrease := false, false
		for i := 1; i+1 < len(s); i++ {
			if s[i-1] == s[i+1] {
				if s[i] == s[i-1] {
					canIncrease = true
				} else {
					canDecrease = true
				}
			}
		}
		answer := 1
		if canIncrease {
			answer++
		}
		if canDecrease {
			answer++
		}
		fmt.Fprintln(out, answer)
	}
}
