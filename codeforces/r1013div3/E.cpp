#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e7);

std::vector<int> is_prime(MAX + 1, 1);
std::vector<int> primes;

void run_case() {
    int N;
    std::cin >> N;
    
    int64_t ans = 0;
    for(int i = 1; i <= N / 2; i++) {
        ans += std::upper_bound(primes.begin(), primes.end(), N / i) - primes.begin();
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    is_prime[0] = 0;
    is_prime[1] = 0;
    
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
