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

int64_t lcm(int64_t a, int64_t b) {
    return a * b / gcd(a, b);
}

void run_case() {
    int64_t A, B, C, D;
    std::cin >> A >> B >> C >> D;

    if(A == 0 && C == 0) {
        std::cout << 0 << '\n';
        return;
    }

    if(A == 0 || C == 0) {
        std::cout << 1 << '\n';
        return;
    }
    int64_t g1 = gcd(A, B);
    int64_t g2 = gcd(C, D);
    
    A /= g1;
    B /= g1;
    C /= g2;
    D /= g2;

    int64_t x = A * D;
    int64_t y = B * C;

    if(x == y) {
        std::cout << 0 << '\n';
        return;
    }

    std::cout << (x % y == 0 || y % x == 0 ? 1 : 2) << '\n';
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
