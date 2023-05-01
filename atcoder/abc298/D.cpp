#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <deque>

using LL = long long;

constexpr LL MOD = 998244353LL;

void run_case() {
    int Q;
    std::cin >> Q;

    std::vector<LL> p_10(Q + 1, 1LL);
    for(int i = 1; i <= Q; i++) {
        p_10[i] = p_10[i - 1] * 10LL % MOD;
    }

    LL x = 1LL;
    LL l = 1LL;
    std::deque<int> digits;
    digits.push_back(1);
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            int D;
            std::cin >> D;

            x = (x * 10LL % MOD) + D;
            x %= MOD;

            l += 1;
            digits.push_back(D);
        } else if(T == 2) {
            x = (x - (p_10[l - 1] * digits.front() % MOD) + MOD) % MOD;

            digits.pop_front();
            l -= 1;
        } else {
            std::cout << x << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
