#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = (LL)1e9 + 7LL;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    LL ans = 1LL;
    LL x = K;
    for(int i = 0; i < N; i++) {
        ans *= x;
        ans %= MOD;
        
        if(i + 1 < K) {
            x -= 1LL;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}

