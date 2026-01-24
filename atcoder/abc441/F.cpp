#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::vector<std::vector<int64_t>> dp1(N + 1, std::vector<int64_t>(M + 1, -1));
    std::vector<std::vector<int64_t>> dp2(N + 1, std::vector<int64_t>(M + 1, -1));
    dp1[0].assign(M + 1, 0);
    dp2[0].assign(M + 1, 0);
    
    for(int i = 1; i <= N; i++) {
        auto [p, v] = A[i - 1];

        for(int j = 0; j <= M; j++) {
            dp1[i][j] = std::max(dp1[i][j], dp1[i - 1][j]);
            if(j - p >= 0) {
                dp1[i][j] = std::max(dp1[i][j], dp1[i - 1][j - p] + v);
            }
            if(j) {
                dp1[i][j] = std::max(dp1[i][j], dp1[i][j - 1]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        auto [p, v] = A[N - i];

        for(int j = 0; j <= M; j++) {
            dp2[i][j] = std::max(dp2[i][j], dp2[i - 1][j]);
            if(j - p >= 0) {
                dp2[i][j] = std::max(dp2[i][j], dp2[i - 1][j - p] + v);
            }
            if(j) {
                dp2[i][j] = std::max(dp2[i][j], dp2[i][j - 1]);
            }
        }
    }

    std::string ans(N, 'C');
    int64_t max_v = dp1[N][M];
    for(int i = 0; i < N; i++) {
        auto [p, v] = A[i];
        int prefix = i;
        int suffix = N - 1 - i;
        bool a = true;
        bool b = false;
        for(int j = 0; j <= M; j++) {
            int k = M - j;
            if(dp1[prefix][j] + dp2[suffix][k] == max_v) {
                a = false;
            }

            if(j <= M - p) {
                k = M - p - j;
                if(dp1[prefix][j] + dp2[suffix][k] == max_v - v) {
                    b = true;
                }
            }
        }
        if(a) {
            ans[i] = 'A'; 
        } else if(b) {
            ans[i] = 'B';
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
