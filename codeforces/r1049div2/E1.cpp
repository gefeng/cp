#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;

int dfs(std::vector<int>& good, int n, int mask, int t, std::vector<std::vector<std::vector<int>>>& dp) {
    if(n == 1) {
        if(t == 0) {
            return mask == 1;
        } else {
            return mask == 0;
        }
    }

    if(dp[t][n][mask] != -1) {
        return dp[t][n][mask];
    }

    int res = 0;
    for(int p : good) {
        if(p >= n) {
            break;
        }
        int n_mask = (mask >> (p + 1)) << p;
        n_mask |= mask & ((1 << p) - 1);
        if(!dfs(good, n - 1, n_mask, t ^ 1, dp)) {
            res = 1;
        }
    }  

    return dp[t][n][mask] = res;
}

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> good;
    for(int i = 0; i < K; i++) {
        int P;
        std::cin >> P;
        good.push_back(P - 1);
    }

    std::vector<std::vector<std::vector<int>>> dp(2, std::vector<std::vector<int>>(N + 1, std::vector<int>(1 << N, -1)));
    int64_t ans = 0;
    if(M == 1) {
        ans = 1;
    } else {
        for(int mask = 0; mask < (1 << N); mask++) {
            if(dfs(good, N, mask, 0, dp)) {
                ans += 2;
            } else {
                ans += 1;
            }
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
