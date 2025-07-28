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
    int64_t A, B, K;
    std::cin >> A >> B >> K;

    if(A <= K && B <= K) {
        std::cout << 1 << '\n';
        return;
    }

    int64_t g = gcd(A, B);
    if(A / g <= K && B / g <= K) {
        std::cout << 1 << '\n';
        return;
    }

    std::cout << 2 << '\n';
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
