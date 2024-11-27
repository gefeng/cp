#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int D;
    std::cin >> D;

    auto is_prime = [](int x) {
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                return false;
            }
        }
        return true;
    };

    int x = D + 1;
    int y = 0;
    while(!is_prime(x)) {
        x += 1; 
    }

    y = x + D;
    while(!is_prime(y)) {
        y += 1;
    }

    std::cout << int64_t(x) * y << '\n';
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
