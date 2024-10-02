#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N;
    std::cin >> N;

    int64_t k1 = 2;
    while(N % k1 == 0) {
        k1 *= 2;
    }

    if(k1 <= N * 2 / (k1 + 1)) {
        std::cout << k1 << '\n';
        return;
    }

    k1 /= 2;
    int64_t k2 = N / k1;
    if(k2 != 1) {
        std::cout << k2 << '\n';
        return;
    }

    std::cout << -1 << '\n';
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
