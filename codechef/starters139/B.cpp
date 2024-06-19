#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = (int)1e6;

std::vector<int> is_prime;
std::vector<int> primes;
std::vector<int64_t> psum;

void run_case() {
    int K;
    std::cin >> K;

    int64_t ans = 0;
    if(is_prime[K]) {
        int i = std::lower_bound(primes.begin(), primes.end(), K) - primes.begin();
        ans += psum[i + 1] * K;
    } else {
        int max_f = 0;
        for(int f = 2; f * f <= K; f++) {
            if(K % f == 0) {
                max_f = std::max(max_f, f);
                max_f = std::max(max_f, K / f);
            }
        }

        for(int p : primes) {
            if(p * max_f <= K) {
                ans += (int64_t)p * K;
            } else {
                break;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    is_prime.resize(MAX + 1, 1);
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    } 

    int n = primes.size();
    psum.resize(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        psum[i] = psum[i - 1] + primes[i - 1];
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
