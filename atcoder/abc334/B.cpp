#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t A, M, L, R;
    std::cin >> A >> M >> L >> R;

    int64_t l = L - A < 0 ? (L - A) / M : (L - A + M - 1) / M;
    int64_t r = R - A < 0 ? -((A - R + M - 1) / M) : (R - A) / M;

    std::cout << r - l + 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
