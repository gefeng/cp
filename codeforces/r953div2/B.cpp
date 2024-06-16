#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, A, B;
    std::cin >> N >> A >> B;

    int64_t x = 2 * (B - A) + 1;
    if(x < 0) {
        std::cout << N * A << '\n';
    } else {
        int64_t k = std::min(N, x / 2);
        std::cout << (2 * B - k + 1) * k / 2 + (N - k) * A << '\n';
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
