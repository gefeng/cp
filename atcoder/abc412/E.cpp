#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int64_t L, R;
    std::cin >> L >> R;
    
    int n = sqrtl(R);
    std::vector<int> is_p(n + 1, 1);
    std::vector<int64_t> primes;
    is_p[0] = 0;
    is_p[1] = 0;
    for(int i = 2; i <= n; i++) {
        if(is_p[i]) {
            primes.push_back(i);
            for(int64_t j = int64_t(i) * i; j <= n; j += i) {
                is_p[j] = 0;
            }
        }
    }

    int size = R - L;  // [L + 1, R]
    is_p.resize(size);
    is_p.assign(size, 1);
    for(int64_t p : primes) {
        for(int64_t i = std::max(p * p, (L + 1 + p - 1) / p * p); i <= R; i += p) {
            is_p[i - L - 1] = 0;
        }
    } 

    int ans = 1;
    for(int i = 0; i < size; i++) {
        if(is_p[i]) {
            ans += 1;
        }
    }

    for(int64_t p : primes) {
        int64_t x = p * p;
        while(x <= R) {
            if(x > L) {
                ans += 1;
            }
            if(x <= R / p) {
                x *= p; 
            } else {
                break;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
