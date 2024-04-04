#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    if(N == K) {
        for(int i = 0; i < N; i++) {
            std::cout << 1 << " \n"[i == N - 1];
        }
    } else if(K == 1) {
        for(int i = 0; i < N; i++) {
            std::cout << i + 1 << " \n"[i == N - 1];
        }
    } else {
        std::cout << -1 << '\n';
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
