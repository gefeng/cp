#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

int64_t dfs(int N, int M, std::vector<int>& A, std::vector<int>& reset, int i, int mask, std::vector<std::vector<int64_t>>& dp) {
    if(i == N) {
        return 1;
    }
    if(dp[i][mask] != -1) {
        return dp[i][mask];
    }

    int64_t res = 0;
    for(int j = 0; j < M; j++) {
        if(mask & (1 << j)) {
            continue;
        }

        int n_mask = mask | (1 << j);
        n_mask &= reset[j];
        res += dfs(N, M, A, reset, i + 1, n_mask, dp);
        res %= MOD;
    }
    return dp[i][mask] = res;
}

void run_case() {
    int M, N;
    std::cin >> M >> N;

    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<int> reset(M, (1 << M) - 1);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            if(A[j] == i) {
                reset[i] ^= 1 << j; 
            }
        }
    }
    
    std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(1 << M, -1));
    std::cout << dfs(N, M, A, reset, 0, 0, dp) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
