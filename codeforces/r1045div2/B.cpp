#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(K % 2 == 1) {
        for(int i = 0; i < N; i++) {
            std::cout << (A[i] % 2 == 0 ? A[i] : A[i] + K) << " \n"[i == N - 1];
        }
    } else {
        int64_t g = 3;
        while(true) {
            if(gcd(K, g) != 1) {
                g += 1;
                continue;
            }

            for(int i = 0; i < N; i++) {
                int r = A[i] % g;
                int t = g - r;
                if(r == 0) {
                    std::cout << A[i] << " \n"[i == N - 1];
                    continue;
                }

                int64_t c = 1;
                while(c * K % g != t) {
                    c += 1;
                }
                std::cout << A[i] + c * K << " \n"[i == N - 1];
            }
            return;
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
