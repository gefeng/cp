#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    int64_t ans = 0;
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
        sum += std::abs(A[i] - B[i]);
    }

    ans = sum;
    std::vector<std::pair<int, int>> a;
     
    auto solve = [&]() {
        if(!a.empty()) {
            std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
                        return x.first < y.first;
                    });

            for(int i = 0; i < N; i++) {
                if(A[i] < B[i]) {
                    int64_t s = sum - std::abs(A[i] - B[i]) - std::abs(a[0].first - a[0].second);
                    s += std::abs(A[i] - a[0].second) + std::abs(B[i] - a[0].first);
                    ans = std::max(ans, s);
                }
            }

            for(int i = 0; i < N; i++) {
                if(A[i] < B[i]) {
                    int64_t s = sum - std::abs(A[i] - B[i]) - std::abs(a.back().first - a.back().second);
                    s += std::abs(A[i] - a.back().second) + std::abs(B[i] - a.back().first);
                    ans = std::max(ans, s);
                }
            }
            std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
                        return x.second < y.second;
                    });

            for(int i = 0; i < N; i++) {
                if(A[i] >= B[i]) {
                    int64_t s = sum - std::abs(A[i] - B[i]) - std::abs(a[0].first - a[0].second);
                    s += std::abs(A[i] - a[0].second) + std::abs(B[i] - a[0].first);
                    ans = std::max(ans, s);
                }
            }

            for(int i = 0; i < N; i++) {
                if(A[i] >= B[i]) {
                    int64_t s = sum - std::abs(A[i] - B[i]) - std::abs(a.back().first - a.back().second);
                    s += std::abs(A[i] - a.back().second) + std::abs(B[i] - a.back().first);
                    ans = std::max(ans, s);
                }
            }
        }
    };

    for(int i = 0; i < N; i++) {
        if(A[i] >= B[i]) {
            a.emplace_back(A[i], B[i]);
        }
    }
    solve();

    a.clear();
    for(int i = 0; i < N; i++) {
        if(A[i] < B[i]) {
            a.emplace_back(A[i], B[i]);
        }
    }
    solve();

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
