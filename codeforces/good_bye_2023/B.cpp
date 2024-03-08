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
    int A, B;
    std::cin >> A >> B;

    int64_t x = lcm(A, B);
    if(x != B) {
        std::cout << x << '\n';
    } else {
        if(A == 1) {
            std::cout << (int64_t)B * B << '\n';
        } else {
            std::cout << (int64_t)B * (B / A) << '\n';
        }
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
