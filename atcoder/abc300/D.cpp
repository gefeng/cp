#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr int MAX = 3e5;

void run_case() {
    LL N;
    std::cin >> N;

    std::vector<bool> is_prime(MAX + 1, true);
    is_prime[1] = false;
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }

    LL ans = 0LL;
    int sz = primes.size();

    for(int i = 0; i < sz; i++) {
        for(int j = i + 1, k = sz - 1; j < sz; j++) {
            LL a = primes[i];
            LL b = primes[j];
            LL x = a * a * b;
            if(x > N) {
                break;
            }
            
            while(k > j && 1LL * primes[k] * primes[k] > N / x) {
                k -= 1;
            }

            if(k == j) {
                break;
            }

            ans += k - j;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
