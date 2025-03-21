#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int64_t N;
    std::cin >> N;
    
    // i = x - y
    for(int64_t i = 1; i * i * i <= N; i++) {
        int64_t p = N - i * i * i;
        int64_t q = 3 * i;
        if(p % q != 0) {
            continue;
        }

        // j = x * y
        int64_t j = p / q;
        int64_t t = i * i + 4 * j; 
        int64_t s = int64_t(sqrtl(t));
        if(s * s != t) {
            continue;
        }

        if((i + s) % 2 == 1) {
            continue;
        }

        int64_t x = (i + s) / 2;
        int64_t y = x - i;
        if(x > y && y > 0) { 
            std::cout << x << ' ' << y << '\n';
            return;
        }
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
