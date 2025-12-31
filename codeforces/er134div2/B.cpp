#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, SX, SY, D;
    std::cin >> N >> M >> SX >> SY >> D;

    SX -= 1;
    SY -= 1;
    
    int d1 = std::min(SX, M - 1 - SY);
    int d2 = std::min(SY, N - 1 - SX);
    int d = std::max(d1, d2);

    std::cout << (d <= D ? -1 : N + M - 2) << '\n';
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
