#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>

double dfs(int N, int X, std::vector<std::tuple<int, int, int>>& A, int cost, int solved, std::vector<std::vector<double>>& dp) {
    if(dp[cost][solved] != -1) {
        return dp[cost][solved];
    } 

    double max_s = 0;
    for(int i = 0; i < N; i++) {
        if(solved & (1 << i)) {
            continue;
        }
        auto [s, c, p] = A[i];
        int n_cost = cost + c;
        double failed = (100 - p) / 100.0;
        double succeed = p / 100.0;
        if(n_cost <= X) { 
            max_s = std::max(max_s, (dfs(N, X, A, n_cost, solved | (1 << i),  dp) + s) * succeed + 
                    dfs(N, X, A, n_cost, solved, dp) * failed);
        }
    }

    return dp[cost][solved] = max_s;
}

void run_case() {
    int N, X;
    std::cin >> N >> X;

    std::vector<std::tuple<int, int, int>> A(N);
    for(int i = 0; i < N; i++) {
        auto& [x, y, z] = A[i];
        std::cin >> x >> y >> z;
    }

    std::vector<std::vector<double>> dp(X + 1, std::vector<double>(1 << N, -1));
    std::cout << std::setprecision(20) << dfs(N, X, A, 0, 0, dp) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
