#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = -INF;
    for(int i = 0; i < N; i++) {
        ans = std::max(ans, A[(i + N - 1) % N] - A[i]);
    }

    if(N > 1) {
        ans = std::max(ans, *std::ranges::max_element(A.begin() + 1, A.end()) - A[0]);
        ans = std::max(ans, A.back() - *std::ranges::min_element(A.begin(), A.end() - 1));
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
