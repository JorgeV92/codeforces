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
	for T > 0 {
		T--
		var s string
		fmt.Fscan(in, &s)
		n := len(s)
		seen := make([]bool, 26)
		k := 0
		for k = 0; k < n; k++ {
			if !seen[s[k]-'a'] {
				seen[s[k]-'a'] = true
			} else {
				break
			}
		}
		ok := true
		for i := k; i < n; i++ {
			if s[i] != s[i-k] {
				ok = false
				break
			}
		}
		if ok {
			fmt.Fprintln(out, "YES")
		} else {
			fmt.Fprintln(out, "NO")
		}
	}
}
