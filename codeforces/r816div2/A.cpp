#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    if(N == 1 && M == 1) {
        std::cout << 0 << '\n';
        return;
    }

    if(N == 1) {
        std::cout << M << '\n';
        return;
    }

    if(M == 1) {
        std::cout << N << '\n';
        return;
    }

    int ans = N + M - 2 + std::min(N, M);

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
