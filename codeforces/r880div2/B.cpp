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
    int N, K, G;
    std::cin >> N >> K >> G;

    LL tot = 1LL * K * G;

    LL x = std::min(1LL * (G + 1) / 2 - 1, tot / N);
    if(x < (G + 1) / 2 - 1) {
        std::cout << tot << '\n'; 
        return;
    }
    
    LL y = tot - x * (N - 1);
    LL r = y % G;
    
    LL ans = x * (N - 1);
    if(r >= (G + 1) / 2) {
        ans -= G - r;
    } else {
        ans += r;
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
