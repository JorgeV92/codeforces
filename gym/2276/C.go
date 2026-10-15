package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

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
		pref := make([]int, n+1)
		cnt := make([]int, k)
		var ans int64
		for i := 1; i <= n; i++ {
			pref[i] = (pref[i-1] + nextInt()) % k
			if i > k {
				cnt[pref[i-k-1]]++
				ans += int64(cnt[pref[i]])
			}
		}
		fmt.Fprintln(out, ans)
	}
}
