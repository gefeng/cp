#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int S, K, M;
    std::cin >> S >> K >> M;

    int r = M % K;
    int t = M / K;
    int u = std::min(S, K);
    if(t % 2 == 0) {
        std::cout << std::max(0, S - r) << '\n';
    } else {
        std::cout << std::max(0, u - r) << '\n';
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
