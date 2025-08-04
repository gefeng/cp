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
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int64_t> dp(4, 0);
    int64_t cnt = 1;
    for(int i = 0; i < N; i++) {
        std::vector<int64_t> n_dp(3, 0);
        if(S[i] == 'a' || S[i] == '?') {
            for(int j = 0; j < 3; j++) {
                if(j == 0) {
                    n_dp[j] += (dp[j] + cnt) % MOD;
                } else {
                    n_dp[j] += dp[j];
                }
                n_dp[j] %= MOD;
            } 
        } 
        if(S[i] == 'b' || S[i] == '?') {
            for(int j = 0; j < 3; j++) {
                if(j == 1) {
                    n_dp[j] += (dp[j] + dp[0]) % MOD;
                } else {
                    n_dp[j] += dp[j];
                }
                n_dp[j] %= MOD;
            }
        } 
        if(S[i] == 'c' || S[i] == '?') {
            for(int j = 0; j < 3; j++) {
                if(j == 2) {
                    n_dp[j] += (dp[j] + dp[1]) % MOD;
                } else {
                    n_dp[j] += dp[j];
                }
                n_dp[j] %= MOD;
            }
        }
        if(S[i] == '?') {
            cnt *= 3;
            cnt %= MOD;
        }

        dp = std::move(n_dp);
    }

    std::cout << dp[2] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
