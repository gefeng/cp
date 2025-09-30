#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

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
    
    std::string S;
    std::cin >> S;

    std::vector<int64_t> dp(1 << N, 0);
    dp[(1 << N) - 1] = 1;
    for(int i = (1 << N) - 1; i > 0; i--) {
        int pre = -1;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) {
                if(S[j] == pre) {
                    continue;
                }
                dp[i ^ (1 << j)] += dp[i];
                dp[i ^ (1 << j)] %= MOD;
                pre = S[j];
            }
        } 
    }
    
    std::cout << dp[0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
