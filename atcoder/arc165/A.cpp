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
    int N;
    std::cin >> N;

    for(int f1 = 2; f1 * f1 <= N; f1++) {
        if(N % f1 == 0) {
            int f2 = N / f1;
            
            if(lcm(f1, f2) == N && f1 + f2 <= N) {
                std::cout << "Yes" << '\n';
                return;
            }
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
