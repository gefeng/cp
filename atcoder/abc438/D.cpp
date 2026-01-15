#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    std::vector<int> C(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    std::vector<int64_t> psum1(N + 1, 0);
    std::vector<int64_t> psum2(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum1[i + 1] = psum1[i] + B[i];
        psum2[i + 1] = psum2[i] + C[i];
    }

    std::vector<int64_t> ds(N, -INF);
    ds[N - 2] = B[N - 2] + C[N - 1];
    for(int i = N - 3; i >= 0; i--) {
        ds[i] = std::max(ds[i + 1] + B[i], psum2[N] - psum2[i + 1] + B[i]);
    }

    int64_t ans = 0;
    int64_t prefix = 0;
    for(int i = 0; i < N - 2; i++) {
        prefix += A[i];
        ans = std::max(ans, ds[i + 1] + prefix);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
