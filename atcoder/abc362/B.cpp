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
    for(int i = 0; i < 6; i++) {
        std::cin >> A[i];
    }

    auto dot_prod = [](int x1, int y1, int x2, int y2) {
        return x1 * x2 + y1 * y2;
    };

    if(dot_prod(A[2] - A[0], A[3] - A[1], A[4] - A[0], A[5] - A[1]) == 0 || 
       dot_prod(A[0] - A[2], A[1] - A[3], A[4] - A[2], A[5] - A[3]) == 0 || 
       dot_prod(A[0] - A[4], A[1] - A[5], A[2] - A[4], A[3] - A[5]) == 0) {
        std::cout << "Yes" << '\n'; 
    } else {
        std::cout << "No" << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
