#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X;
    std::cin >> X;

    auto is_prime = [](int64_t x) {
        if(x == 1) {
            return false;
        }
        if(x == 2) {
            return true;
        }
        for(int64_t f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                return false;
            }
        }
        return true;
    };

    auto next_prime = [&](int64_t x) {
        int64_t y = x + 1;
        while(!is_prime(y)) {
            y += 1;
        }
        return y;
    };

    int64_t ans = 0;
    if(is_prime(X)) {
        ans = X * next_prime(X);
    } else {
        int64_t x = next_prime(X);
        int64_t y = next_prime(x);
        ans = x * y;
    }

    std::cout << ans << '\n';
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
