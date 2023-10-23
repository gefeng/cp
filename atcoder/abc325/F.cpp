#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

void run_case() {
    int N;
    int64_t L1, C1, K1, L2, C2, K2;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    } 

    std::cin >> L1 >> C1 >> K1 >> L2 >> C2 >> K2;

    // dp[i][j] how many type 2 sensors needed to cover first i sections when j type 1 sensors are used.
    std::vector<int> dp(K1 + 1, INF); 
    dp[0] = 0;
    for(int i = 0; i < N; i++) {
        std::vector<int> ndp(K1 + 1, INF);
        for(int j = 0; j <= K1; j++) {
            for(int k = 0; k <= j; k++) {
                int used = j - k; 
                int64_t len = L1 * used;
                if(dp[k] != INF && len >= A[i]) {
                    ndp[j] = std::min(ndp[j], dp[k]);
                }
                
                if(dp[k] != INF && len < A[i]) {
                    int need = (A[i] - len + L2 - 1) / L2;
                    if(need + dp[k] <= K2) {
                        ndp[j] = std::min(ndp[j], dp[k] + need);
                    }
                }
            }
        }

        std::swap(dp, ndp);
    }

    int64_t ans = (int64_t)1e18; 
    for(int i = 0; i <= K1; i++) {
        if(dp[i] != INF) {
            ans = std::min(ans, i * C1 + dp[i] * C2);
        }
    }

    std::cout << (ans == (int64_t)1e18 ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
