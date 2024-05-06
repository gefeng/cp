#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 9> A{};
    std::array<int, 8> B{};

    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < 9; i++) {
        std::cin >> A[i];
        sum1 += A[i];
    }

    for(int i = 0; i < 8; i++) {
        std::cin >> B[i];
        sum2 += B[i];
    }

    int ans = std::max(0, sum1 - sum2 + 1);
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
