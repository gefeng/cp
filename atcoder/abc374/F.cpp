#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(1e18);

void run_case() {
    int N, K, X;
    std::cin >> N >> K >> X;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    std::vector<int64_t> shipping_days;
    shipping_days.push_back(0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            shipping_days.push_back(A[i] + int64_t(j) * X);            
        }
    }   

    std::sort(shipping_days.begin(), shipping_days.end());
    shipping_days.erase(std::unique(shipping_days.begin(), shipping_days.end()), shipping_days.end());

    int m = shipping_days.size();
    std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(m, INF));
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(i - j < 0) {
                break;
            }

            for(int k = 0; k < m; k++) {
                int64_t d = shipping_days[k];
                if(dp[i - j][k] != INF) {
                    if(d == 0 || d + X <= A[i - 1]) {
                        int p = std::lower_bound(shipping_days.begin(), shipping_days.end(), A[i - 1]) - shipping_days.begin();
                        int64_t cost = A[i - 1] * j - psum[i] + psum[i - j];
                        dp[i][p] = std::min(dp[i][p], dp[i - j][k] + cost);
                    } else {
                        int p = std::lower_bound(shipping_days.begin(), shipping_days.end(), d + X) - shipping_days.begin();
                        int64_t cost = (d + X) * j - psum[i] + psum[i - j];
                        dp[i][p] = std::min(dp[i][p], dp[i - j][k] + cost);
                    }
                }
            }
        }
    }

    int64_t ans = INF;
    for(int i = 0; i < m; i++) {
        ans = std::min(ans, dp[N][i]);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
