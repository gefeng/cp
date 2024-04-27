#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

double dfs(int64_t X, int64_t Y, int64_t A, int64_t N, std::map<int64_t, double>& dp) {
    if(N == 0) {
        return 0.0;
    }

    if(dp.find(N) != dp.end()) {
        return dp[N];
    }

    double pick1 = dfs(X, Y, A, N / A, dp) + X;
    double pick2 = 0.0;
    
    double cost = (6.0 / 25.0) * double(Y);
    double p = 1.0 / 5.0;
    for(int d = 2; d <= 6; d++) {
        pick2 += dfs(X, Y, A, N / d, dp) * p + cost;
    }

    double res = std::min(pick1, pick2);
    dp[N] = res;
    return res;
}

void run_case() {
    int64_t N, A, X, Y;
    std::cin >> N >> A >> X >> Y;

    std::map<int64_t, double> dp;
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    std::cout << dfs(X, Y, A, N, dp) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
