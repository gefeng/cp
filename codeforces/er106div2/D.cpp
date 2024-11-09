#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = int(2e7);

std::vector<int> cnt_prime_factors;

void run_case() {
    int C, D, X;
    std::cin >> C >> D >> X;
    
    std::vector<int> factors;
    for(int f = 1; f * f <= X; f++) {
        if(X % f == 0) {
            factors.push_back(f);
            if(f != X / f) {
                factors.push_back(X / f);
            }
        }
    }

    std::sort(factors.begin(), factors.end());
    
    int ans = 0;
    for(int g : factors) {
        if((X / g + D) % C == 0) {
            int k = (X / g + D) / C;
            ans += std::pow(2, cnt_prime_factors[k]);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cnt_prime_factors.resize(MAX + 1, 0);
    for(int i = 2; i <= MAX; i++) {
        if(cnt_prime_factors[i] == 0) {
            for(int j = i; j <= MAX; j += i) {
                cnt_prime_factors[j] += 1;
            }
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
