package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func aliceWins(p []int, k int) bool {
	var cnt [22]int
	for i := range p {
		if p[i] < 0 {
			continue
		}
		sz := 0
		for v := i; p[v] >= 0; {
			u := p[v]
			p[v] = -1
			v = u
			sz++
		}
		if sz > k+1 {
			return false
		}
		cnt[sz]++
	}

	if k == 1 {
		return cnt[2] == 0 || len(p)%2 == 1
	}
	if cnt[k+1] > 0 {
		if cnt[k+1] > 1 {
			return false
		}
		need := len(p) - (k + 1) - cnt[1] + cnt[1]%(k+1)
		return 0 < need && need <= k
	}

	var dp [21][21]int
	for j := 0; j <= k; j++ {
		for c := 0; c <= k; c++ {
			dp[j][c] = k + 1
		}
	}
	dp[0][0] = 0
	m := 0
	for sz := k; sz >= 2; sz-- {
		for cnt[sz] > 0 && m < 2*k {
			cnt[sz]--
			var ndp [21][21]int
			for j := 0; j <= k; j++ {
				for c := 0; c <= k; c++ {
					ndp[j][c] = k + 1
				}
			}
			for j := 0; j <= k; j++ {
				for c := 0; c <= k; c++ {
					v := dp[j][c]
					if v > k {
						continue
					}
					if j+sz <= k && v < ndp[j+sz][c+1] {
						ndp[j+sz][c+1] = v
					}
					if m-c < k {
						v += sz - 1
					}
					if v < ndp[j][c] {
						ndp[j][c] = v
					}
				}
			}
			dp = ndp
			m++
		}
	}
	for j := 0; j <= k; j++ {
		for c := 0; c <= k; c++ {
			if dp[j][c] <= k {
				return true
			}
		}
	}
	return false
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
		p := make([]int, n)
		for i := range p {
			p[i] = nextInt() - 1
		}
		if aliceWins(p, k) {
			fmt.Fprintln(out, "Alice")
		} else {
			fmt.Fprintln(out, "Bob")
		}
	}
}
