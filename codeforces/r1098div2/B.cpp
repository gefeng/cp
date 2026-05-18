#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X1, X2, K;
    std::cin >> N >> X1 >> X2 >> K;

    if(N == 2 || N == 3) {
        std::cout << 1 << '\n';
        return;
    }

    int d1 = std::abs(X2 - X1);
    int d2 = N - d1;

    int64_t ans = std::min(d1, d2) - 1 + K + 1;

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
