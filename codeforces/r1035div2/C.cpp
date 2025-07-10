#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, L, R, K;
    std::cin >> N >> L >> R >> K;
    
    if(N % 2 == 0) {
        if(N == 2) {
            std::cout << -1 << '\n';
            return;
        }

        int hb = -1;
        for(int i = 60; i >= 0; i--) {
            if(L & (int64_t(1) << i)) {
                hb = i;
                break;
            }
        }

        hb += 1;
        int64_t last = (int64_t(1) << hb);
        if(last > R) {
            std::cout << -1 << '\n';
            return;
        }
        
        std::cout << (K < N - 1 ? L : last) << '\n';
    } else {
        std::cout << L << '\n';
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
