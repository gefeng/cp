#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e6);
constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    std::vector<int64_t> dp(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        int x = A[i];
        std::vector<int> prime_factors;
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                prime_factors.push_back(f);
                while(x % f == 0) {
                    x /= f;
                }
            }
        }
        if(x > 1) {
            prime_factors.push_back(x);
        }

        int n = prime_factors.size();

        for(int mask = 1; mask < (1 << n); mask++) {
            int cnt = __builtin_popcount(mask);
            int prod = 1; 
            for(int j = 0; j < n; j++) {
                if(mask & (1 << j)) {
                    prod *= prime_factors[j];
                }
            } 

            if(cnt % 2 == 1) {
                sum += dp[prod];
                sum %= MOD;
            } else {
                sum -= dp[prod];
                sum += MOD;
                sum %= MOD;
            }
        }

        for(int mask = 1; mask < (1 << n); mask++) {
            int prod = 1; 
            for(int j = 0; j < n; j++) {
                if(mask & (1 << j)) {
                    prod *= prime_factors[j];
                }
            } 
            dp[prod] += i == 0 ? 1 : sum;
            dp[prod] %= MOD;
        }
        
        if(i == N - 1) {
            ans = sum;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
