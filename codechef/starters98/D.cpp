#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)2e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N, 0);
    std::vector<int> B(N, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int64_t> dp1(N * 2 + 1, 0);
    std::vector<int64_t> dp2(N * 2 + 1, 0);
    std::vector<int64_t> best1(N * 2 + 1, 0);
    std::vector<int64_t> best2(N * 2 + 1, 0);
    for(int i = 0; i < N; i++) {
        int64_t max_v = std::max(A[i], B[i]);
        int64_t sum = A[i] + B[i];
        dp1[2 * i + 1] = std::max(max_v, dp1[2 * i] + max_v);
        dp1[2 * i + 2] = std::max(max_v, std::max(sum, dp1[2 * i] + sum));

        best1[2 * i + 1] = std::max(best1[2 * i], dp1[2 * i + 1]);
        best1[2 * i + 2] = std::max(best1[2 * i + 1], dp1[2 * i + 2]);
    }

    for(int i = 0; i < N; i++) {
        int64_t max_v = std::max(A[N - i - 1], B[N - i - 1]);
        int64_t sum = A[N - i - 1] + B[N - i - 1];
        dp2[2 * i + 1] = std::max(max_v, dp2[2 * i] + max_v);
        dp2[2 * i + 2] = std::max(max_v, std::max(sum, dp2[2 * i] + sum));

        best2[2 * i + 1] = std::max(best2[2 * i], dp2[2 * i + 1]);
        best2[2 * i + 2] = std::max(best2[2 * i + 1], dp2[2 * i + 2]);
    }

    int64_t ans = INF;
    for(int i = 0; i < N; i++) {
        int64_t a = A[i];
        int64_t b = B[i];
        for(int j = 0; j < 2; j++) {
            int64_t max_sum = std::max(best1[2 * i], best2[2 * N - 2 * i - 2]);
            max_sum = std::max(max_sum, std::max(a, dp1[2 * i] + a));
            max_sum = std::max(max_sum, std::max(b, dp2[2 * N - 2 * i - 2] + b));
            max_sum = std::max(max_sum, std::max(a + b, dp1[2 * i] + dp2[2 * N - 2 * i - 2] + a + b));
            max_sum = std::max(max_sum, std::max(dp1[2 * i] + a + b, dp2[2 * N - 2 * i - 2] + a + b));
            
            ans = std::min(ans, max_sum);

            std::swap(a, b);
        }
    }

    std::cout << std::max((int64_t)0, ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
