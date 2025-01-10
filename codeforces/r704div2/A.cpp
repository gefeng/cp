#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int64_t P;
    std::array<int64_t, 3> A = {};
    std::cin >> P;

    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    int64_t ans = INF;
    for(int i = 0; i < 3; i++) {
        int64_t k = (P + A[i] - 1) / A[i];
        ans = std::min(ans, k * A[i] - P);
    } 

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
