#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, M, K;
    std::cin >> N >> M >> K;

    std::array<int, 4> a = {2, 4, 8, 6};

    if(N >= M) {
        int64_t x = M - K;
        int64_t c = (N - M + 1 + x - 1) / x;
        N -= c * x;
    } 
    if(K == M - 1 && N == M - 1) {
        std::cout << 0 << '\n';
    } else {
        std::cout << a[(N - 1) % 4] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
