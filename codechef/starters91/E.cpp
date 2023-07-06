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
    LL N, K;
    std::cin >> N >> K;

    LL cnt_odd = (N + 1LL) / 2LL;
    LL cnt_eve = N / 2LL;
    
    if(cnt_odd < K || (cnt_odd - K + 1LL) % 2LL == 0) {
        std::cout << "NO" << '\n';
        return;
    }

    if(N % 2LL == 0) {
        std::cout << "YES" << '\n';
    } else {
        cnt_eve -= K;
        cnt_odd -= K;
        if(cnt_eve + cnt_odd >= 2) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    }
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
