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

    if(N == 1 || M == 1) {
        std::cout << "YES" << '\n';
        return;
    }

    if(M >= N) {
        std::cout << "NO" << '\n';
        return;
    }

    if(N % M == 0) {
        std::cout << "NO" << '\n';
        return;
    }

    for(int f = 2; f * f <= N; f++) {
        if(N % f == 0) {
            if(M >= N / f || M >= f) {
                std::cout << "NO" << '\n';
                return;
            }
        }
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
