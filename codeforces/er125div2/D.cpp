#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <ranges>

void run_case() {
    int N, C;
    std::cin >> N >> C;
    
    std::vector<std::tuple<int64_t, int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        auto& [c, d, h] = A[i];
        std::cin >> c >> d >> h;
    }

    int M;
    std::cin >> M;
    std::vector<std::pair<int64_t, int64_t>> B(M);
    for(int i = 0; i < M; i++) {
        auto& [d, h] = B[i];
        std::cin >> d >> h;
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return std::get<0>(x) < std::get<0>(y);
            });

    std::vector<int64_t> best(C + 1, 0);

    for(int i = 0; i < N; ) {
        int64_t max_v = 0;
        int64_t c = std::get<0>(A[i]);
        while(i < N && std::get<0>(A[i]) == c) {
            max_v = std::max(max_v, std::get<1>(A[i]) * std::get<2>(A[i]));
            i += 1;
        }

        for(int64_t k = c, p = max_v; k <= C; k += c, p += max_v) {
            best[k] = std::max(best[k], p);
        }
    }

    for(int i = 1; i <= C; i++) {
        best[i] = std::max(best[i], best[i - 1]);
    }

    for(int i = 0; i < M; i++) {
        auto [d, h] = B[i];
        auto it = std::lower_bound(best.begin(), best.end(), d * h + 1);
        std::cout << (it == best.end() ? -1 : it - best.begin()) << " \n"[i == M - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
