#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(M);
    std::vector<int64_t> psum(M + 1, 0);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::ranges::sort(A);

    for(int i = 0; i < M; i++) {
        psum[i + 1] = psum[i] + A[i].first;
    }

    int64_t ans = 0;
    for(int i = 0; i < M; i++) {
        auto it = std::upper_bound(A.begin(), A.end(), A[i].second, [](const auto& x, const auto& y) {
            return x < y.first;
        });
        
        int n = N;
        int cnt = std::min(n, static_cast<int>(A.end() - it));
        int64_t score = psum[M] - psum[M - cnt];    
        n -= cnt;
        if(n) {
            if(it - A.begin() > i) {
                score += A[i].first;
                n -= 1;
            }
            score += static_cast<int64_t>(A[i].second) * n;
        }

        ans = std::max(ans, score);
    }

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
