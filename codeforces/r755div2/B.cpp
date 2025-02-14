#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, M;
    std::cin >> N >> M;

    auto solve = [](int64_t N, int64_t M) {
        int64_t cnt = M / 3;
        int64_t rem = M % 3;
        
        int64_t blue = cnt * N;
        if(rem == 1) {
            blue += N / 3 + (N % 3 == 0 ? 0 : 1);
        }
        if(rem == 2) {
            blue += N / 3 * 2 + (N % 3 == 0 ? 0 : 2);
        }
        return blue;
    };

    std::cout << std::min(solve(N, M), solve(M, N)) << '\n';
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
