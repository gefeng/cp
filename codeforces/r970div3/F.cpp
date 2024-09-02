#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t p = (int64_t(N) * (N - 1) % MOD) * q_pow(2, MOD - 2) % MOD;
    p = q_pow(p, MOD - 2);

    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        sum %= MOD;
    }
    
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        sum -= A[i];
        sum += MOD;
        sum %= MOD;
        
        ans += A[i] * sum % MOD;
        ans %= MOD;
    }

    ans *= p;
    ans %= MOD;
    
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
