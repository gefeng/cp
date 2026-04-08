#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, A, B, C;
    std::cin >> N >> M >> A >> B >> C;
    
    int d = std::min(N, M);
    int ans = d * C;
    
    N -= d;
    M -= d;
    ans += N * A + M * B;

    std::cout << ans << '\n';
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
