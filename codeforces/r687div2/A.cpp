#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, M, R, C;
    std::cin >> N >> M >> R >> C;

    int64_t ans = std::max(R - 1 + C - 1, R - 1 + M - C);
    ans = std::max(ans, N - R + C - 1);
    ans = std::max(ans, N - R + M - C);
    
    std::cout << ans << '\n';
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
