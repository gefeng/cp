#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = 2e9;

void run_case() {
    int N;
    std::cin >> N;

    int max_v = -INF;
    int min_v = INF;
    
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;

        max_v = std::max(max_v, X);
        min_v = std::min(min_v, X);
    }

    if(min_v < 0) {
        std::cout << min_v << '\n';
    } else {
        std::cout << max_v << '\n';
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
