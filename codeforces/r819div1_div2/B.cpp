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

    if(N % 2 == 1) {
        if(M - N + 1 < 1) {
            std::cout << "No" << '\n';
            return;
        }
        std::cout << "Yes" << '\n';
        for(int i = 0; i < N; i++) {
            std::cout << (i < N - 1 ? 1 : M - N + 1) << " \n"[i == N - 1];
        }
    } else {
        if(M - N + 2 < 1 || (M - N + 2) % 2 == 1) {
            std::cout << "No" << '\n';
            return;
        }
        std::cout << "Yes" << '\n';
        for(int i = 0; i < N - 2; i++) {
            std::cout << 1 << ' ';
        }
        std::cout << (M - N + 2) / 2 << ' ' << (M - N + 2) / 2 << '\n';
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
