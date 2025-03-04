#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

void run_case() {
    int64_t N, K;
    std::cin >> N >> K;

    int64_t ans = 0;
    int64_t n = sqrt(N);
    for(int64_t p = 2; p <= std::min(n, K); p++) {
        int64_t x = N;
        std::vector<int> digits;
        while(x) {
            digits.push_back(x % p);
            x /= p;
        }
        
        int size = digits.size();
        int64_t d = 1;
        for(int i = size - 1; i >= 0; i--) {
            x += digits[i] * d;
            d *= p;
        }
        ans += x % MOD;
        ans %= MOD;
    }  

    auto cal = [&](int64_t x) {
        int64_t res = x * (x + 1) * (2 * x + 1) / 6;
        res %= MOD;
        return res;
    };

    if(K > n) {
        int64_t p_l = n + 1;
        int64_t p_r = std::min(K, N);

        ans += N * (((p_l + p_r) * (p_r - p_l + 1) / 2) % MOD) % MOD;
        ans %= MOD;

        int64_t sum_1 = 0;
        int64_t sum_2 = 0;
        for(int64_t l = p_l; l <= p_r; ) {
            int64_t r = std::min(p_r, N / (N / l));
            int64_t q = N / l;

            sum_1 += q * (r - l + 1) % MOD; 
            sum_1 %= MOD;
            sum_2 += q * ((cal(r) - cal(l - 1) + MOD) % MOD) % MOD;
            sum_2 %= MOD;

            l = r + 1;
        }

        ans += (sum_1 - sum_2 + MOD) % MOD;
        ans %= MOD;
    }
    
    if(K > N) {
        ans += ((K - N) % MOD) * N % MOD;
        ans %= MOD;
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
