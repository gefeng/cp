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

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return x.first + x.second < y.first + y.second;
            });

    int64_t sum_p = 0;
    for(auto [x, y] : A) {
        sum_p += y;
    }

    int64_t sum = 0;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i].first + A[i].second;
        if(sum_p < sum) {
            ans = i;
            break;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
