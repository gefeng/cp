#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int64_t>> A(N, std::vector<int64_t>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    auto prod = [N](const auto& lhs, const auto& rhs) {
        std::vector<std::vector<int64_t>> ret(N, std::vector<int64_t>(N, INF));
        for(int k = 0; k < N; k++) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    ret[i][j] = std::min(ret[i][j], lhs[i][k] + rhs[k][j]);
                }
            }
        }
        return ret;
    };

    std::vector<std::vector<int64_t>> a(A);
    std::vector<std::vector<int64_t>> ans(A);
    K -= 1;
    
    while(K) {
        if(K & 1) {
            ans = prod(ans, a);
        }
        a = prod(a, a);
        K >>= 1;
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i][i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
