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

    if(N > M) {
        std::swap(N, M);
    }

    int64_t ans = (N * M - (N * M / 2)) * 2;
    
    if(N == 2 || M == 2) {
        ans += (N * M / 2 * 2) - (N * M / 4) * 2;
    } else {
        ans += 4;
    }

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
