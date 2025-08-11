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

    std::string A, B;
    std::cin >> A >> B;
    
    std::vector<int> a(N, 0);
    std::vector<std::pair<int, int>> b(N, {0, 0});
    std::vector<std::vector<int64_t>> psum_a(2, std::vector<int64_t>(N + 1, 0));
    std::vector<std::vector<int64_t>> psum_b(2, std::vector<int64_t>(N + 1, 0));

    a[0] = A[0] - '0';
    b[0] = {B[0] - '0', 1 - (B[0] - '0')};
    for(int i = 1; i < N; i++) {
        a[i] = a[i - 1] + A[i] - '0';
        b[i].first = b[i - 1].first + B[i] - '0';
        b[i].second = i + 1 - b[i].first;
    }

    std::ranges::sort(b, [](const auto& x, const auto& y) {
                return x.second - x.first < y.second - y.first;
            });

    for(int i = 0; i < N; i++) {
        psum_a[0][i + 1] = psum_a[0][i] + a[i];
        psum_b[0][i + 1] = psum_b[0][i] + b[i].first;
        psum_a[1][i + 1] = psum_a[1][i] + i + 1 - a[i];
        psum_b[1][i + 1] = psum_b[1][i] + b[i].second;
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int d = a[i] - (i + 1 - a[i]);
        int j = std::lower_bound(b.begin(), b.end(), d, [](const auto& x, int y) {
                    return x.second - x.first < y; 
                }) - b.begin();
        int64_t cnt = static_cast<int64_t>(a[i]) * (N - j) + static_cast<int64_t>(i + 1 - a[i]) * j + 
            psum_b[1][j] + psum_b[0][N] - psum_b[0][j];
        ans += cnt;
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
