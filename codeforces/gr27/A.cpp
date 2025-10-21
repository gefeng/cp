#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, R, C;
    std::cin >> N >> M >> R >> C;
    
    R -= 1;
    C -= 1;

    int64_t ans = int64_t(N - R - 1) * M;
    ans += int64_t(N) * M - (int64_t(R) * M + C + 1) - (N - R - 1);

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
