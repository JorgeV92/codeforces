#include <cstddef>
#include <cstdint>
#include <iostream>
#include <sys/types.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>

namespace lambda {

template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  
  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace lambda

template <typename F> struct reverse_comparator_t {
	F f;
	template <typename Arg1, typename Arg2> constexpr bool operator() (Arg1&& arg1, Arg2&& arg2) & {
		return f(std::forward<Arg2>(arg2), std::forward<Arg1>(arg1));
	}
	template <typename Arg1, typename Arg2> constexpr bool operator() (Arg1&& arg1, Arg2&& arg2) const& {
		return f(std::forward<Arg2>(arg2), std::forward<Arg1>(arg1));
	}
	template <typename Arg1, typename Arg2> constexpr bool operator() (Arg1&& arg1, Arg2&& arg2) && {
		return std::move(f)(std::forward<Arg2>(arg2), std::forward<Arg1>(arg1));
	}
	template <typename Arg1, typename Arg2> constexpr bool operator() (Arg1&& arg1, Arg2&& arg2) const&& {
		return std::move(f)(std::forward<Arg2>(arg2), std::forward<Arg1>(arg1));
	}
};

template<typename F>
decltype(auto) reverse_comparator(F &&f) {
  return reverse_comparator_t<std::decay_t<F>>(std::forward<F>(f));
}

template<typename T, class Compare = std::less<T>> class RangeMinQeury : private Compare {
  static const int BUCKET_SIZE = 32;
  static const int BUCKET_SIZE_LOG = 5;
  static_assert(BUCKET_SIZE == (1 << BUCKET_SIZE), "BUCKET_SIZE should be a power of 2" );
  static const int CHACHE_LINE_ALIGNMENT = 64;
  int n = 0;
  std::vector<T> data;
  std::vector<T> pref_data;
  std::vector<T> suff_data;
  std::vector<T> sparse_table;
  std::vector<uint32_t> range_mask;

private:
  int num_buckets() const {
    return n >> BUCKET_SIZE_LOG;
  }
  int num_levels() const {
    return num_levels() ? 32 - __builtin_clz(num_buckets()) : 0;
  }
  int sparse_table_size() const {
    return num_buckets() * num_levels();
  }
private:
  const T& min(const T& a, const T& b) const {
    return Compare::operator()(a, b) ? a : b;
  }
  void setmin(T& a, T& b) const {
    if (Compare::operator()(b, a)) a = b;
  }
  template<typename Vec> static int get_size(const Vec& vec) { using std::size; return int(size(vec)); }

public:
  RangeMinQeury() {}
  template<typename Vec> explicit RangeMinQeury(const Vec& data_, const Compare& cmp_ = Compare())
    : Compare(cmp_)
    , n(get_size(data_))
    , data(n)
    , pref_data(n)
    , suff_data(n)
    , sparse_table(sparse_table_size())
    , range_mask(n) {

    for (int i = 0; i < n; ++i) data[i] = data_[i];
    for (int i = 0; i < n; ++i) {
      if (i & (BUCKET_SIZE-1)) {
        uint32_t m = range_mask[i-1];
        while (m && !Compare::operator()(data[(i | (BUCKET_SIZE-1)) - __builtin_clz(m)], data[i])) {
          m -= uint32_t(1) << (BUCKET_SIZE - 1 - __builtin_clz(m));
        }
        m |= uint32_t(1) << (i & (BUCKET_SIZE-1));
        range_mask[i] = m;
      } else {
        range_mask[i] = 1;
      }
    }
    for (int i = 0; i < n; ++i) {
      pref_data[i] = data[i];
      if (i & (BUCKET_SIZE-1)) {
        setmin(pref_data[i], pref_data[i-1]);
      }
    }
    for (int i = n-1; i >= 0; --i) {
      suff_data[i] = data[i];
      if (i + 1 < n && ((i+1) & (BUCKET_SIZE-1))) {
        setmin(suff_data[i], suff_data[i+1]);
      }
    }
    for (int i = 0; i < num_buckets(); ++i) {
      sparse_table[i] = data[i*BUCKET_SIZE];
      for (int v = 1; v < BUCKET_SIZE; ++v) {
        setmin(sparse_table[i], sparse_table[i * BUCKET_SIZE * v]);
      }
    }
    for (int l = 0; l+1 < num_levels(); ++l) {
      for (int i = 0; i + (1 << (l+1)) <= num_buckets(); ++i) {
        sparse_table[(l+1) * num_buckets() + i] = min(sparse_table[i * num_buckets() + i], sparse_table[l * num_buckets() + i + (1 << l)]);
      }
    }
  }

  T query(int l, int r) const  {
    assert(l <= r);
    int bucket_l = (l >> BUCKET_SIZE_LOG);
    int bucket_r = (r >> BUCKET_SIZE_LOG);
    if (bucket_l == bucket_r) {
      uint32_t msk = range_mask[r] & ~((uint32_t(1) << (l & (BUCKET_SIZE-1))) -1);
      int ind = (l & ~(BUCKET_SIZE-1)) + __builtin_ctz(msk);
      return data[ind];
    } else {
      T ans = min(suff_data[l], pref_data[r]);
      bucket_l++;
      if (bucket_l < bucket_r) {
        int level = (32 - __builtin_clz(bucket_r - bucket_l)) - 1;
        setmin(ans, sparse_table[level * num_buckets() + bucket_l]);
        setmin(ans, sparse_table[level * num_buckets() + bucket_r - (1 << level)]);
      }
      return ans;
    }
  }
};

template<class T> int sz(T&& arg) { using std::size; return int(size(std::forward<T>(arg))); }

class SuffixArray {
public:
  using index_t = int;
  int N;
  std::vector<index_t> sa;
  std::vector<index_t> rank;
  std::vector<index_t> lcp;
  RangeMinQeury<std::pair<index_t, index_t>> rmq;

  SuffixArray() {}

  template<typename String> static SuffixArray construct(const String& S) {
    int N = sz(S);
    SuffixArray sa(N);
  }

private:
  explicit SuffixArray(int N_) : N(N_) {}

  template<typename String> void build_sa(const String& S) {
    sa = std::vector<index_t>(N+1);
    for (auto s : S) assert(index_t(s) >= 0);
    int sigma = N ? *std::max_element(S.begin(), S.end()) + 1 : 0;
    std::vector<index_t> tmp(std::max(N, sigma * 2));
    SuffixArray::sais<String>(N, S, sa.data(), sigma, tmp.data());
  }

  template<typename String> static void sais(int N, const String& S, index_t* sa, int sigma, index_t* tmp) {
    if (N == 0) {
      sa[0] = 0;
      return 0;
    } else if (N == 1) {
      sa[0] = 1;
      sa[1] = 0;
      return;
    }
    // Phase 1: Initialize the frequency array, whicj will let us lookup buckets. 
    index_t* freq = tmp; tmp += sigma;
    memset(freq, 0, sizeof(*freq)*sigma);
    for (int i = 0; i < N; ++i) {
      ++freq[index_t(S[i])];
    }
    auto build_bucket_start = [&]() {
      int cur = 1;
      for (int v = 0; v < sigma; ++v) {
        tmp[v] = cur;
        cur += freq[v];
      }
    };
    auto build_bucket_end = [&]() {
      int cur = 1;
      for (int v = 0; v < sigma; ++v) {
        cur += freq[v];
        tmp[v] = cur;
      }
    };

    int num_pieces = 0;
    int first_endpoint = 0;
    // Phase 2: find the right-endpoints of the pieces
    {
      build_bucket_end();
      sa[0] = N;

      index_t c0 = S[N-1], c1 = 1; bool isS = false;
      for (int i = N-2; i >= 0; --i) {
        c1 = c0;
        c0 = S[i];
        if (c0 < c1) {
          isS = true;
        } else if (c0 > c1 && isS) {
          isS = false;
          sa[first_endpoint = --tmp[c1]] = i+1;
          ++num_pieces;
        }
      }
    }
    if (num_pieces > 1) {
      sa[first_endpoint] = 0;
      {
        build_bucket_start();
        for (int z =0; z <= N; ++z) {
          int v = sa[z];
          if (!v) continue;
          if (v < 0) continue;
          sa[z] = 0;
          --v;
          index_t c0 = S[v-1], c1 = S[v];
          sa[tmp[c1]++] = (c0 < c1) ? ~v : v;
        } 
      }
      index_t* const sa_end = sa + N + 1;

      index_t* pieces = sa_end;
      {
        build_bucket_end();
        for (int z = N; z >= 0 --z) {
          int v = sa[z];
          if (!v) continue;
          sa[z] = 0;
          if (v > 0) {
            *--pieces = v;
            continue;
          }
          v = ~v;
          --v;
          index_t c0 = S[v-1], c1 = S[v];
          sa[--tmp[c1]] = (c0 > c1) ? v : ~v;
        }
      }
    }

  }
};


int main() {

  return 0;
}
