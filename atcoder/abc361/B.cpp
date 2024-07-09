#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 6> A;
    std::array<int, 6> B;
    
    for(int i = 0; i < 6; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < 6; i++) {
        std::cin >> B[i];
    }

    auto solve = [](int x1, int y1, int x2, int y2) {
        return std::min(y1, y2) - std::max(x1, x2);
    };

    for(int i = 0; i < 3; i++) {
        if(solve(A[i], A[i + 3], B[i], B[i + 3]) <= 0) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
