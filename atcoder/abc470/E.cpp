#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

double dfs(int L, int n, int kn, std::vector<std::vector<std::vector<double>>>& dp) {
    if(L == 0) {
        return 0.0;
    }
    if(n == 0) {
        return 0.0;
    }

    int left = n - kn;
    int ukn = (left - kn) / 2;

    if(ukn == 0) {
        return kn;
    }

    if(dp[L][n][kn] != -1.0) {
        return dp[L][n][kn];
    }

    double res = 0.0;
    double p = 0.0;

    if(ukn > 1) {
        // 2 different unknown cards
        p = static_cast<double>(left - kn) * (left - 1 - kn - 1) / (left * (left - 1));
        res += dfs(L - 1, n, kn + 2, dp) * p;
    }

    // 1 pair of unknown cards
    p = static_cast<double>(left - kn) / (left * (left - 1));
    res += (dfs(L, n - 2, kn, dp) + 1) * p;


    if(kn) {
        if(L > 1) {
            // 1 unknown card then 1 known card
            p = static_cast<double>(left - kn) * kn / (left * (left - 1));
            res += (dfs(L - 1, n - 2, kn, dp) + 1) * p;
        }

        // 1 known card
        p = static_cast<double>(kn) / left;
        res += (dfs(L, n - 2, kn - 1, dp) + 1) * p;
    }

    return dp[L][n][kn] = res;
}

void run_case() {
    int N, L;
    std::cin >> N >> L;
    
    std::vector<int> A(N);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    std::vector<std::vector<std::vector<double>>> dp(L + 1, std::vector<std::vector<double>>(N * 2 + 1, std::vector<double>(N + 1, -1.0)));
    double ev = dfs(L, N * 2, 0, dp);
    double ans = ev / N * sum;

    std::cout << std::setprecision(20) << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
