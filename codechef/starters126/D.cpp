#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MOD = (int64_t)1e9 + 7;

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto is_prime = [](int x) {
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                return false;
            }
        }
        return true;
    };

    std::vector<int> primes;
    for(int i = 2; i <= K; i++) {
        if(is_prime(i)) {
            primes.push_back(i);
        }
    }

    if(primes.back() != K) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int64_t> p2(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }

    int m = primes.size();

    std::vector<int> freq(1 << m, 0);
    for(int x : A) {
        if(x % K != 0) {
            continue;
        }
        int mask = 0;
        for(int i = 0; i < m; i++) {
            if(x % primes[i] == 0) {
                mask |= 1 << i;
            }
        }
        for(int smask = mask; smask > 0; smask = (smask - 1) & mask) {
            freq[smask] += 1;
        }
    }

    int64_t ans = 0;
    for(int i = 1; i < (1 << m); i++) {
        if(!(i & (1 << (m - 1))) || freq[i] == 0) {
            continue;
        }

        int cnt = __builtin_popcount(i); 

        if(cnt % 2 == 1) {
            ans += (p2[freq[i]] - 1 + MOD) % MOD; 
            ans %= MOD;
        } else {
            ans -= (p2[freq[i]] - 1 + MOD) % MOD;
            ans += MOD;
            ans %= MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
