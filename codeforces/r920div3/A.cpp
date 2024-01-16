#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int min_x = 1000;
    int min_y = 1000;
    int max_x = -1000;
    int max_y = -1000;

    for(int i = 0; i < 4; i++) {
        int X, Y;
        std::cin >> X >> Y;

        min_x = std::min(min_x, X);
        min_y = std::min(min_y, Y);
        max_x = std::max(max_x, X);
        max_y = std::max(max_y, Y);
    }

    std::cout << (max_x - min_x) * (max_y - min_y) << '\n';
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
