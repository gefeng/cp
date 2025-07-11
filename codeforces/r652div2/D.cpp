#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;
constexpr int MAX = 2e6;

std::vector<int64_t> psum(MAX + 2, 0);
std::vector<int64_t> p_2(MAX + 1, 1);
std::vector<int64_t> dp(MAX + 1, 0);

void run_case() {
    int N;
    std::cin >> N;

    int64_t ans = dp[N];

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int64_t p_3 = 1;
    for(int i = 0; i <= MAX; i++) {
        psum[i + 1] = (psum[i] + p_3) % MOD;
        p_3 *= 3;
        p_3 %= MOD;
    }

    for(int i = 1; i <= MAX; i++) {
        p_2[i] = p_2[i - 1] * 2 % MOD;
    }

    dp[3] = 4;
    dp[4] = 4;
    for(int i = 5; i <= MAX; i++) {
        dp[i] = (dp[i - 1] + (dp[i - 2] * 2 % MOD)) % MOD;

        if(i % 3 == 0) {
            dp[i] += 4;
            dp[i] %= MOD;
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
