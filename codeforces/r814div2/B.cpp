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

    if(K % 2 == 0) {
        for(int i = 2; i <= N; i += 2) {
            if(i % 4 == 0) {
                continue;
            }
            if((i + K) % 4 != 0) {
                std::cout << "NO" << '\n';
                return;
            }
        }

        std::cout << "YES" << '\n';
        for(int i = 1; i <= N; i += 2) {
            if((i + 1) % 4 == 0) {
                std::cout << i << ' ' << i + 1 << '\n';
            } else {
                std::cout << i + 1 << ' ' << i << '\n';
            }
        }
    } else {
        std::cout << "YES" << '\n';
        for(int i = 1; i <= N; i += 2) {
            std::cout << i << ' ' << i + 1 << '\n';
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
