#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, S;
    std::cin >> N >> S;

    if(S % (N * N) == 0) {
        std::cout << S / (N * N) << '\n';
        return;
    }

    int64_t x = S - N * N + 1;
    int64_t y = N * N - N + 1;

    std::cout << (x + y - 1) / y << '\n';
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
