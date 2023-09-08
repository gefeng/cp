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
    int N, X, Y;
    std::cin >> N >> X >> Y;

    int64_t cnt1 = N / X;
    int64_t cnt2 = N / Y;
    int64_t cnt3 = (int64_t)N / lcm(X, Y);
    cnt1 -= cnt3;
    cnt2 -= cnt3;

    int64_t sum1 = (N - cnt1 + 1 + N) * cnt1 / 2;    
    int64_t sum2 = (1 + cnt2) * cnt2 / 2;
    std::cout << sum1 - sum2 << '\n';
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
