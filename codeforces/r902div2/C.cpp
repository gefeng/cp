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
    
    if(K > 3) {
        std::cout << 0 << '\n';
        return;
    }

    if(N == 1) {
        if(K == 1) {
            std::cout << 1 << '\n';
        } else if(K == 2) {
            std::cout << M << '\n';
        } else {
            std::cout << 0 << '\n';
        }
        return;
    }

    if(K == 1) {
        std::cout << 1 << '\n';
        return;
    }

    if(K == 2) {
        if(M <= N) {
            std::cout << M << '\n';
        } else {
            std::cout << N + (M / N - 1) << '\n';
        }
        return;
    }

    if(M <= N) {
        std::cout << 0 << '\n';
        return;
    }

    std::cout << M - N - (M / N - 1) << '\n';
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
