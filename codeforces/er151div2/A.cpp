#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, X;
    std::cin >> N >> K >> X;

    if(X != 1) {
        std::cout << "YES" << '\n';
        std::cout << N << '\n';
        for(int i = 0; i < N; i++) {
            std::cout << 1 << " \n"[i == N - 1];
        }
    } else {
        if(K == 1 || N == 1) {
            std::cout << "NO" << '\n';
            return;
        }

        if(N % 2 == 0) {
            std::cout << "YES" << '\n';
            int cnt = N / 2;
            std::cout << cnt << '\n';
            for(int i = 0; i < cnt; i += 1) {
                std::cout << 2 << " \n"[i == cnt - 1];
            }
            return;
        } else {
            if(K == 2) {
                std::cout << "NO" << '\n';
                return;
            }

            std::cout << "YES" << '\n';
            int tot = 1 + (N - 3) / 2;
            std::cout << tot << '\n';

            std::cout << 3 << ' ';
            int cnt = (N - 3) / 2;
            for(int i = 0; i < cnt; i++) {
                std::cout << 2 << ' ';
            }
            std::cout << '\n';
        }
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
