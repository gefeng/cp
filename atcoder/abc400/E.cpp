#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e6);
constexpr int64_t UB = int64_t(1e12);

void run_case() {
    int Q;
    std::cin >> Q;

    std::vector<int> primes;
    std::vector<int> is_prime(MAX + 1, 1);
    
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    
    int size = primes.size();

    std::vector<int64_t> all;
    for(int i = 0; i < size; i++) {
        int64_t p_1 = int64_t(primes[i]) * primes[i];
        int64_t x = 1;
        if(UB / p_1 < p_1) {
            break;
        }
        while(x <= UB / p_1) {
            x *= p_1;
            for(int j = i + 1; j < size; j++) {
                int64_t p_2 = int64_t(primes[j]) * primes[j];
                int64_t y = 1;
                
                if(p_2 > UB / x) {
                    break;
                }

                while(y <= UB / p_2) {
                    y *= p_2;
                    if(y <= UB / x) {
                        all.push_back(x * y);
                    } else {
                        break;
                    }
                }
            }
        }
    }

    std::sort(all.begin(), all.end());
    
    for(int i = 0; i < Q; i++) {
        int64_t A;
        std::cin >> A;
        
        std::cout << *std::prev(std::upper_bound(all.begin(), all.end(), A)) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
