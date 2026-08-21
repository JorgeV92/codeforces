package main

import (
	"bufio"
	"fmt"
	"os"
)

type Pair struct {
	val int 
	cnt int64
}

func canonicalize(a []int, m int) []Pair {
	r := make([]Pair, 0, len(a))
	for _, v := range a {
		var cnt int64 = 1
		for v % m == 0 {
			v  /= m 
			cnt *= int64(m)
		}
		if len(r) > 0 && r[len(r)-1].val == v {
			r[len(r)-1].cnt += cnt
		} else {
			r = append(r, Pair{val: v, cnt: cnt})
		}
	}
	return r 
}

func equal(a, b []Pair) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false 
		}
	}
	return true 
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	var t int 
	fmt.Fscan(in, &t)

	for tt := 0; tt < t; tt++ {
		var n, m int 
		fmt.Fscan(in, &n, &m)

		A := make([]int, n)
		for i := range A {
			fmt.Fscan(in, &A[i])
		}

		var k int
		fmt.Fscan(in, &k)

		B := make([]int, k)
		for i := range B {
			fmt.Fscan(in, &B[i])
		}

		ca := canonicalize(A, m)
		cb := canonicalize(B, m)

		if equal(ca, cb) {
			fmt.Fprintln(out, "Yes")
		} else {
			fmt.Fprintln(out, "No")
		}

	}
}
