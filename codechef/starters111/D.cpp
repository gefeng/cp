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

    if(N == 1 || N == 2) {
        std::cout << -1 << '\n';
        return;
    }

    /*for(int a = 1; a <= N; a++) {
        for(int b = 1; b <= N; b++) {
            for(int c = 1; c <= N; c++) {
                if(lcm(a, b) + lcm(b, c) + lcm(a, c) == N) {
                    std::cout << a << ' ' << b << ' ' << c << '\n';
                }
            }
        }
    }*/

    if(N % 2 == 0) {
        if((N / 2 - 1) % 2 == 0) {
            std::cout << N / 2 - 1 << ' ' << 2 << ' ' << 2 << '\n';
        } else {
            int x = N;
            while(x % 2 == 0) {
                x /= 2;
            }

            if(x == 1) {
                std::cout << -1 << '\n';
                return;
            }

            int a = N / x;
            x = (x - 1) / 2;
            std::cout << a << ' ' << a * x << ' ' << 1 << '\n';
        }
    } else {
        std::cout << (N - 1) / 2 << ' ' << 1 << ' ' << 1 << '\n';
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
