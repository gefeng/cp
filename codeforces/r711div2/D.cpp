#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>

constexpr int64_t C = int64_t(1e5);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::tuple<int, int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        auto& [t, x, y] = A[i];
        std::cin >> t >> x >> y;
    }
    
    std::vector<int> ans(M + 1, -1);
    std::vector<int> dp(M + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        auto [t, x, y] = A[i];
        std::vector<int> ndp(M + 1, 0);
        if(t == 1) {
            for(int j = 0; j <= M; j++) {
                if(dp[j]) {
                    ndp[j] = 1;
                    int cnt = 1;
                    int64_t k = j;
                    k += (x + C - 1) / C;
                    while(k <= M && cnt <= y && !dp[k]) {
                        ndp[k] = 1; 
                        ans[k] = i + 1;
                        k += (x + C - 1) / C;
                        cnt += 1;
                    }
                }
            }
        } else {
            ndp[0] = 1;
            for(int j = 1; j <= M; j++) {
                if(dp[j]) {
                    ndp[j] = 1;
                    int cnt = 1;
                    int64_t k = j;
                    k = (k * x + C - 1) / C;
                    while(k <= M && cnt <= y && !dp[k]) {
                        ndp[k] = 1;
                        ans[k] = i + 1;
                        k = (k * x + C - 1) / C;
                        cnt += 1;
                    }
                }
            }
        }

        std::swap(dp, ndp);
    }

    for(int i = 1; i <= M; i++) {
        std::cout << ans[i] << " \n"[i == M];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
