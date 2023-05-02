#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    LL N;
    std::cin >> N;

    if(N == 2) {
        std::cout << 1 << '\n';
        return;
    }

    auto get_factors = [](LL x) {
        std::vector<LL> factors;
        for(LL f = 2LL; f * f <= x; f++) {
            if(x % f == 0) {
                factors.push_back(f);
                if(x / f != f) {
                    factors.push_back(x / f);
                }
            }        
        }
        return factors;
    };

    std::vector<LL> factors1 = get_factors(N);
    std::vector<LL> factors2 = get_factors(N - 1);

    LL ans = 2LL + factors2.size();
    for(LL f : factors1) {
        LL x = N;
        while(x % f == 0) {
            x /= f;
        }

        if(x % f == 1) {
            ans += 1LL;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
