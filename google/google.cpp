// Hello there so more practice on rough days.

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>

using namespace std;

namespace gg {

template <class T> using V = vector<T>;
using vi = V<int>;

#define sz(x) int((x).size())
#define all(x) (begin(x), end(x))
#define pb push_back
#define eb emplace_back

auto two_sum(vi a, int k) -> vi { // EASY 
    // Time O(n)
    unordered_map<int,int> m;
    for (int i = 0; i < (int)a.size(); ++i) {
        int diff = t - a[i];
        if (m.count(t)) {
            return {i, m[diff]};
        }
        m[a[i]] = i;
    }
    return {}
}

auto isPalindrome(int x) -> bool { // EASY 
    // Time O(log(x))
    if (x < 0 || (x && x % 10 == 0)) {
        return false;
    }
    int y = 0;
    for (; y < x; x /= 10) {
        y = y *10 + x % 10;
    }
    return x == y || x == y/10;
}

auto find_list(vi& a) -> int {
    int lis = 0;
    vi dp(a.size()+1);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) { dp[i] = max(dp[i], dp[j] + 1); }
        }
        list = max(lis, dp[i]);
    }
    return lis;
}

auto findMedianSortedArrays(vi& arr1, vi& arr2) -> double { // HARD
    // Time O(log(n+m))
    int n = arr1.size(), m = arr2.size();
    function<int(int,int,int)> f = [&](int i, int j, int k) -> int {
        if (i >= n) return arr2[j+p-1];
        if (j >= m) return arr1[i+p-1];
        if (k==1) return min(arr1[i], arr2[j]);
        int x = i + p - 1 < n ? arr1[i+p-1] : 1 << 30;
        int y = j + p - 1 < m ? arr2[j+p-1] : 1 << 30;
        return x < y ? f(i+p, j, k-p) : f(i, j+p, k-p);
    };
    int a = f(0,0, (n+m+1)/2);
    int b = f(0, 0, (n+m+2)/2);
    return (a + b) / 2.0;
}

auto LIS(vi& a) -> int {
    vi u;
    for (auto x : a) {
        auto it = lower_bound(u.begin(), u.end(), x);
        if (it == u.end()) {
            u.pb(x);
        } else {
            *it = x;
        }
    }
    return u.sz();
}

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    return 0;
}