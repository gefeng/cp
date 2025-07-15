#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    int tot_space = 0;
    int tot_water = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        tot_space += A[i].first;
        tot_water += A[i].second;
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(tot_space + 1, -1));
    dp[0][0] = 0;

    for(int i = 0; i < N; i++) {
        std::vector<std::vector<int>> n_dp(N + 1, std::vector<int>(tot_space + 1, -1));
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k <= tot_space; k++) {
                if(dp[j][k] == -1) {
                    continue;
                }
                n_dp[j][k] = std::max(n_dp[j][k], dp[j][k]);
                n_dp[j + 1][k + A[i].first - A[i].second] = std::max(n_dp[j + 1][k + A[i].first - A[i].second], dp[j][k] + A[i].second);
            }    
        }
        dp = std::move(n_dp);
    }

    std::cout << std::setprecision(20);
    for(int i = 1; i <= N; i++) {
        double max_v = 0.0;
        for(int j = 0; j <= tot_space; j++) {
            if(dp[i][j] == -1) {
                continue;
            }
            int left = tot_water - dp[i][j];
            max_v = std::max(max_v, dp[i][j] + std::min(double(j), left / 2.0));
        }
        std::cout << max_v << " \n"[i == N];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
