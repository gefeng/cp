#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

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
    
    std::vector<int64_t> p2(31, 1);
    for(int i = 1; i <= 30; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }

    int64_t ans = 0;
    for(int p = 0; p < 30; p++) {
        std::vector<int> a(N, 0);
        for(int i = 0; i < N; i++) {
            if(A[i] & (1 << p)) {
                a[i] = 1;
            }
        }

        std::array<int64_t, 2> cnt = {};
        std::array<int64_t, 2> sum = {};
        cnt[0] = 1;
        int xor_sum = 0;
        for(int i = 0; i < N; i++) {
            xor_sum ^= a[i];
            cnt[xor_sum] = (cnt[xor_sum] + 1) % MOD;
            sum[xor_sum] = (((sum[xor_sum] + i) % MOD) + 1) % MOD;
            
            ans += (((i + 1) % MOD) * cnt[xor_sum ^ 1] % MOD) * p2[p] % MOD;
            ans %= MOD;
            
            ans -= sum[xor_sum ^ 1] * p2[p] % MOD;
            ans += MOD;
            ans %= MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
