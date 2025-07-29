#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::tuple<int, int, int>> A(N);
    for(int i = 0; i < N; i++) {
        auto& [h, w, idx] = A[i];
        std::cin >> h >> w;
        idx = i;
    }

    std::vector<int> ans(N, -1);

    std::ranges::sort(A);
    std::vector<int> min_w(N, -1);
    std::vector<int> min_h(N, -1);
    
    for(int i = 0; i < N; i++) {
        min_w[i] = i == 0 ? i : (std::get<1>(A[i]) < std::get<1>(A[min_w[i - 1]]) ? i : min_w[i - 1]);
    }

    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && std::get<0>(A[i]) == std::get<0>(A[j])) {
            if(j && std::get<1>(A[min_w[j - 1]]) < std::get<1>(A[i])) {
                ans[std::get<2>(A[i])] = std::get<2>(A[min_w[j - 1]]);
            }
            i += 1;
        }
    }

    for(int i = 0; i < N; i++) {
        auto [h, w, idx] = A[i];
        if(ans[idx] == -1) {
            auto it = std::lower_bound(A.begin(), A.end(), w, [](const auto& x, const auto& y) {
                        return std::get<0>(x) < y;
                    });
            
            if(it != A.begin()) {
                int j = std::prev(it) - A.begin();
                if(std::get<1>(A[min_w[j]]) < h) {
                    ans[idx] = std::get<2>(A[min_w[j]]);
                }
            }
        }
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return std::get<1>(x) < std::get<1>(y);
            });

    for(int i = 0; i < N; i++) {
        min_h[i] = i == 0 ? i : (std::get<0>(A[i]) < std::get<0>(A[min_h[i - 1]]) ? i : min_h[i - 1]);
    }

    for(int i = 0; i < N; i++) {
        auto [h, w, idx] = A[i];
        if(ans[idx] == -1) {
            auto it = std::lower_bound(A.begin(), A.end(), h, [](const auto& x, const auto& y) {
                        return std::get<1>(x) < y;
                    });
            
            if(it != A.begin()) {
                int j = std::prev(it) - A.begin();
                if(std::get<0>(A[min_h[j]]) < w) {
                    ans[idx] = std::get<2>(A[min_h[j]]);
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << (ans[i] == -1 ? -1 : ans[i] + 1) << " \n"[i == N - 1];
    }
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
