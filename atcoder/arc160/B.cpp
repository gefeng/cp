#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = 998244353LL;

void run_case() {
    LL N;
    std::cin >> N;

    LL sr = (LL)sqrt(N);
    
    LL ans = (sr * sr % MOD) * sr % MOD;

    LL x = 0LL;
    for(LL i = sr + 1LL; i <= N; ) {
        int ni = N / (N / i) + 1;
        
        x += (1LL * (N / i) * (N / i) % MOD) * (ni - i) % MOD;
        x %= MOD;

        i = ni;
    }
    
    ans += x * 3LL % MOD;
    ans %= MOD;

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
