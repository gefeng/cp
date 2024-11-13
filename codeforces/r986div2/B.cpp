#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, B, C;
    std::cin >> N >> B >> C;

    if(B == 0) {
        if(N <= C) {
            std::cout << N << '\n';
        } else {
            if(N - 1 == C || N - 2 == C) {
                std::cout << N - 1 << '\n';
            } else {
                std::cout << -1 << '\n';
            }
        }
    } else {
        if(N >= C) {
            int64_t i = (N - C + B - 1) / B;
            std::cout << N - i << '\n'; 
        } else {
            std::cout << N << '\n';
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
