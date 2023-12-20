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

    if(X > Y) {
        int s = Y + 1;
        int x = X / s + ((X % s) ? 1 : 0);
    
        std::cout << std::max(x, X - 2 * Y) << '\n';
    } else {
        std::cout << 1 << '\n';
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
