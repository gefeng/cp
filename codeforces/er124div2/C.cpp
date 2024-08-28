#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int64_t ans = std::abs(A[0] - B[0]) + std::abs(A[N - 1] - B[N - 1]);
    ans = std::min(ans, std::abs(A[0] - B[N - 1]) + std::abs(A[N - 1] - B[0]));
 
    int64_t min1 = INF;
    int64_t min2 = INF;
    int64_t min3 = INF;
    int64_t min4 = INF;
    for(int i = 0; i < N; i++) {
        min1 = std::min(min1, std::abs(A[0] - B[i]));
        min2 = std::min(min2, std::abs(A[N - 1] - B[i]));
        min3 = std::min(min3, std::abs(B[0] - A[i]));
        min4 = std::min(min4, std::abs(B[N - 1] - A[i]));
    }

    ans = std::min(ans, min1 + min2 + min3 + min4);
    ans = std::min(ans, min1 + min3 + std::abs(A[N - 1] - B[N - 1]));
    ans = std::min(ans, min2 + min4 + std::abs(A[0] - B[0]));
    ans = std::min(ans, min2 + min3 + std::abs(A[0] - B[N - 1]));
    ans = std::min(ans, min1 + min4 + std::abs(A[N - 1] - B[0]));

    std::cout << ans << '\n';
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
