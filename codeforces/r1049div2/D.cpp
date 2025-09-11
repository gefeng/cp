#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return x.first + x.second < y.first + y.second;
            });

    int64_t ans = 0;
    int64_t sum = 0;
    for(auto [l, r] : A) {
        sum += r;
    }

    if(N % 2 == 0) {
        ans = sum;
        for(int i = 0; i < N / 2; i++) {
            ans -= A[i].first + A[i].second; 
        }
    } else {
        int64_t half = 0;
        for(int i = 0; i < N / 2; i++) {
            half += A[i].first + A[i].second;
        }

        for(int i = 0; i < N; i++) {
            auto [l, r] = A[i];
            if(i < N / 2) {
                ans = std::max(ans, sum - r - (half - l - r + A[N / 2].first + A[N / 2].second));
            } else {
                ans = std::max(ans, sum - r - half);
            }
        }
    }

    for(auto [l, r] : A) {
        ans += r - l;
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
