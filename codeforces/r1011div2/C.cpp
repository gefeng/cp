#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t X, Y;
    std::cin >> X >> Y;

    if(X == Y) {
        std::cout << -1 << '\n';
        return;
    }

    if(X < Y) {
        std::swap(X, Y);
    }

    int64_t p_2 = 1;
    while(p_2 < X) {
        p_2 *= 2; 
    }
    std::cout << p_2 - X << '\n'; 
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
