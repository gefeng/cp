#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X1, Y1, X2, Y2;
    std::cin >> N >> X1 >> Y1 >> X2 >> Y2;
    X1 -= 1;
    X2 -= 1;
    Y1 -= 1;
    Y2 -= 1;
    
    auto f = [](int N, int x, int y) {
        if(x >= N / 2) {
            x = N - 1 - x;
        }

        if(y >= N / 2) {
            y = N - 1 - y;
        }
        
        return std::min(x, y);
    };

    std::cout << std::abs(f(N, X1, Y1) - f(N, X2, Y2)) << '\n';
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
