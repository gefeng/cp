#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::vector<std::vector<int>> primes;

void run_case() {
    int A, B, C;
    std::cin >> A >> B >> C;
    
    int64_t p1 = 0;
    int64_t p2 = 0;
    if(A == B) {
        p1 = primes[A - C][0];
        p2 = primes[B - C][1];
    } else {
        p1 = primes[A - C][0];
        p2 = primes[B - C][0];
    }

    std::cout << p1 * int64_t(std::pow(10, C - 1)) << ' ' << p2 * int64_t(std::pow(10, C - 1)) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    auto is_prime = [](int x) {
        for(int f = 2; f * f <= x; f++) {
            if(x % f == 0) {
                return false;
            }
        }
        return true;
    };

    for(int base = 1; base <= int(1e8); base *= 10) {
        int x = base + 1;
        std::vector<int> p;
        while(p.size() < 2) {
            if(is_prime(x)) {
                p.push_back(x);
            }
            x += 1;
        }
        primes.push_back(p);
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
