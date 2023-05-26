#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, K;
    std::cin >> X >> K;

    int d = abs(X);
    if(d % K != 0) {
        std::cout << 1 << '\n' << X << '\n';
    } else {
        std::cout << 2 << '\n' << (X < 0 ? X + 1 : X - 1) << ' ' << (X < 0 ? -1 : 1) << '\n';
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
