#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 3> A;
    std::cin >> A[0] >> A[1] >> A[2];
    
    std::sort(A.begin(), A.end());

    int ans = std::abs(A[1] - A[0]) + std::abs(A[1] - A[2]);
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
