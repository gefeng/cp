#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <atcoder/convolution.hpp>

constexpr int MAX = int(1e6);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> a(MAX + 1, 0);
    for(int x : A) {
        a[x] = 1;
    }

    std::vector<int> c = atcoder::convolution(a, a);
    int64_t ans = 0;
    for(int x : A) {
        ans += (c[2 * x] - 1) / 2;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
