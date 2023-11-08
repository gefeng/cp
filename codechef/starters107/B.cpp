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

    if(N < K) {
        std::cout << (N % K) / 2 << '\n';
    } else {
        int64_t x = (N % K) / 2;
        int64_t y = ((N % K) + K) / 2;
        
        if(x * ((N - x) % K) > y * ((N - y) % K)) {
            std::cout << x << '\n';
        } else {
            std::cout << y << '\n';
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
