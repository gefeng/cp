#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y;
    std::cin >> X >> Y;
    
    if(X == 0 && Y == 0) {
        std::cout << 0 << '\n';
        return;
    }

    int d = static_cast<int>(sqrt(X * X + Y * Y));
    if(d * d == X * X + Y * Y) {
        std::cout << 1 << '\n';
        return;
    }
    std::cout << 2 << '\n';
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
