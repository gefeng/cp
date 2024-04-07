#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, K;
    std::cin >> N >> K;

    if(N < K) {
        std::cout << "No" << '\n';
        return;
    }

    if(N == K) {
        std::cout << "Yes" << '\n' << 1 << '\n' << 1 << '\n';
        return;
    }

    int64_t p1 = N - K + 1;
    if(N / p1 + (N % p1) == K) {
        std::cout << "Yes" << '\n' << 2 << '\n';
        std::cout << p1 <<  ' ' << 1 << '\n';
        return;
    }

    std::cout << "No" << '\n';
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
