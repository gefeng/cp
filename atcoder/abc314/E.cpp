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
    int N, M;
    std::cin >> N >> M;


    std::vector<int> A(N);
    std::vector<std::vector<int>> B(N);

    for(int i = 0; i < N; i++) {
        int C, P;
        std::cin >> C >> P;

        A[i] = C;
        B[i].resize(P);
        for(int j = 0; j < P; j++) {
            std::cin >> B[i][j];
        }
    }

    std::vector<double> dp(M + 1, 1e15);
    dp[0] = 0;

    for(int i = 1; i <= M; i++) {
        for(int j = 0; j < N; j++) {
            int sz = B[j].size(); 
            int cnt_zero = 0;
            double ev = A[j];
            for(int k = 0; k < sz; k++) {
                if(B[j][k]) {
                    ev += dp[std::max(0, i - B[j][k])] * (1.0 / sz);
                } else {
                    cnt_zero += 1;
                }
            }
            ev *= (double)sz / (sz - cnt_zero);
            dp[i] = std::min(dp[i], ev);
        }
    }

    std::cout << std::setprecision(20) << dp[M] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
