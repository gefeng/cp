#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    if(K < 2) {
        std::cout << "NO" << '\n';
        return;
    }

    if(K == 2) {
        std::cout << (N == 1 && M == 0 ? "YES" : "NO") << '\n';
        return;
    }

    if(M < N - 1) {
        std::cout << "NO" << '\n';
        return;
    }
 
    int64_t ub = int64_t(N) * (N - 1) / 2;
    if(M > ub) {
        std::cout << "NO" << '\n';
        return;
    }

    if(K == 3) {
        std::cout << (M == ub ? "YES" : "NO") << '\n';
        return;
    }

    std::cout << "YES" << '\n';
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
