#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int64_t A, B, C, M;
    std::cin >> A >> B >> C >> M;

    auto solve = [&](int64_t a, int64_t b, int64_t c) {
        int64_t res = 0;
        
        int64_t x = a * b / gcd(a, b);
        int64_t y = a * c / gcd(a, c);
        int64_t z = (x * c) / gcd(x, c);
        
        int64_t tot = M / a;
        int64_t three = M / z;
        int64_t one = tot - M / x - M / y + three;
        int64_t two = tot - one - three;

        res = one * 6 + two * 3 + three * 2;
        
        return res;
    };

    std::cout << solve(A, B, C) << ' ' << solve(B, A, C) << ' ' << solve(C, A, B) << '\n';
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
