#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, M, X, Y;
    std::cin >> N >> M >> X >> Y;

    int64_t ans = std::max((X - 1) * M, (N - X) * M);
    
    ans = std::max(ans, N * (Y - 1));
    ans = std::max(ans, N * (M - Y));

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
