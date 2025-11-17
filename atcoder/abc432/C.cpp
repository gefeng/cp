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
    int64_t X, Y;
    std::cin >> N >> X >> Y;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    for(int i = 1; i < N; i++) {
        int64_t x = X * (A[i] - A[0]);
        int64_t y = Y - X;

        if(x % y != 0) {
            std::cout << -1 << '\n';
            return;
        }
    }

    int64_t ans = A[0];
    for(int i = 1; i < N; i++) {
        int64_t x = X * (A[0] - A[i]);
        int64_t y = Y - X;
        int64_t d = x / y;
        if(A[0] + d < 0) {
            std::cout << -1 << '\n';
            return;
        }
        ans += A[0] + d;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
