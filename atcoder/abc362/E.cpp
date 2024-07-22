#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int, int> m;
    m[0] = 0;
    int val = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            m[A[j] - A[i]] = 0;
        }
    }

    int o = 0;
    for(auto& [x, v] : m) {
        if(x == 0) {
            o = val; 
        }
        v = val++;
    }

    std::vector<std::vector<std::vector<int64_t>>> dp(N, std::vector<std::vector<int64_t>>(N + 1, std::vector<int64_t>(val + 1, 0)));
    std::vector<int64_t> ans(N + 1, 0);
    
    for(int i = 0; i < N; i++) {
        dp[i][1][o] = 1;
    }

    for(int i = 1; i < N; i++) {
        for(int s = 0; s < i; s++) {
            int d = m[A[i] - A[s]];
            dp[i][2][d] += dp[s][1][o];
            dp[i][2][d] %= MOD;
        }

        for(int j = 3; j <= i + 1; j++) {
            for(int s = 0; s < i; s++) {
                int d = m[A[i] - A[s]];
                
                if(dp[s][j - 1][d] != 0) {
                    dp[i][j][d] += dp[s][j - 1][d];
                    dp[i][j][d] %= MOD;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= i + 1; j++) {
            for(int k = 0; k <= val; k++) {
                ans[j] += dp[i][j][k];
                ans[j] %= MOD;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        std::cout << ans[i] << " \n"[i == N];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
