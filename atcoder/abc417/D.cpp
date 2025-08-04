#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>

constexpr int MAX = 500;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::tuple<int, int, int>> A(N);
    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        auto& [P, X, Y] = A[i];
        std::cin >> P >> X >> Y;
        psum[i + 1] = psum[i] + Y;
    }

    std::vector<std::vector<int>> dp((MAX << 1) + 1, std::vector<int>(N, -1));
    for(int i = N - 1; i >= 0; i--) {
        auto [p, a, b] = A[i];
        for(int j = 0; j <= MAX << 1; j++) {
            if(p >= j) {
                dp[j][i] = i == N - 1 ? j + a : dp[j + a][i + 1];
            } else {
                dp[j][i] = i == N - 1 ? std::max(0, j - b) : dp[std::max(0, j - b)][i + 1];
            }
        }
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;

        int res = 0;
        if(X > MAX << 1) {
            int lo = 0;
            int hi = N - 1;
            int j = -1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;

                if(X - psum[mid + 1] <= MAX << 1) {
                    j = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if(j != -1) {
                res = j == N - 1 ? X - psum[j + 1] : dp[X - psum[j + 1]][j + 1];
            } else {
                res = X - psum[N];
            }
        } else {
            res = dp[X][0];
        }

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
