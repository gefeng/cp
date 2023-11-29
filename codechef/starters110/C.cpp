#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int MAX = (int)1e6;

std::vector<int> is_prime;
std::vector<int> primes;

void run_case() {
    int H;
    std::cin >> H;

    int ans = -1;
    for(int i = 1; i <= 20; i++) {
        int h = H;
        int a = 1; 
        int t = 1;
        while(h > 0) {
            if(t == i) {
                auto it = std::upper_bound(primes.begin(), primes.end(), h);
                if(it != primes.begin()) {
                    it--;
                    h -= *it;
                } else {
                    h -= a;
                    a *= 2;
                }
            } else {
                h -= a;
                a *= 2;
            }
            t += 1;
        }

        if(h == 0) {
            ans = ans == -1 ? t - 1 : std::min(ans, t - 1);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    is_prime.resize(MAX + 1, 1); 
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
