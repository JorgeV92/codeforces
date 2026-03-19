// Sieve of Eratosthenes

// Sieve of Erathosthenes is an algorithm for finding all prime numbers 
//  in a segmenet [1, n] using O(nloglogn) machine instructions.

#include <vector>

std::vector<bool> sieve_v1(int n) {
    std::vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i*i <= n) {
            for (int j = i*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

std::vector<bool> sieve_v2(int n) {
    std::vector<bool> is_prime(n+1,true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    } 
}

// block sieving 
int count_primes(int n) {
    const int S = 10000;

    std::vector<int> primes;
    int nsqrt = std::sqrt(n);
    std::vector<char> is_prime(nsqrt + 2, true);
    for (int i = 2; i*i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i*i; j <= nsqrt; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int res = 0;
    std::vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        std::fill(block.begin(), block.end(), true);
        int start = k * S;
        for (int p : primes) {
            int start_idx = (start + p - 1) / p;
            int j = std::max(start_idx, p) * p - start;
            for (; j < S; j += p) {
                block[j] = false;
            }
        }
        if (k == 0) 
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                res++;
        }
    }
    return res;
}