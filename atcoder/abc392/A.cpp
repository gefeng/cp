#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 3> A = {};
    
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    std::cout << (A[0] * A[1] == A[2] ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
