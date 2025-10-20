#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    if(N == 2) {
        std::cout << -1 << '\n';
        return;
    }
    
    if(N == 3) {
        std::cout << 1 << ' ' << 3 << '\n' << 2 << ' ' << 3 << '\n';
        return;
    }

    if(N == 4) {
        for(int i = 2; i <= N; i++) {
            std::cout << 1 << ' ' << i << '\n';
        }
        return;
    }

    if(N == 5) {
        for(int i = 1; i < N - 1; i++) {
            std::cout << i << ' ' << i + 1 << '\n';
        }
        std::cout << 1 << ' ' << 5 << '\n';
        return;
    }

    for(int i = 1; i < 4; i++) {
        std::cout << i << ' ' << i + 1 << '\n';
    }
    std::cout << 1 << ' ' << N << '\n';

    for(int i = 5; i < N; i++) {
        std::cout << 2 << ' ' << i << '\n';
    }
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
