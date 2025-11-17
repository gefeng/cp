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
    std::array<int, 3> A = {};
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);
    
    std::cout << A[2] * 100 + A[1] * 10 + A[0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
