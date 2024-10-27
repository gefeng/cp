#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

void run_case() {
    int64_t N;
    int K;
    std::cin >> N >> K;

    if(K == 1) {
        std::cout << (N % MOD) << '\n';
        return;
    }

    int now = 1;
    int pre = 1;
    int idx = 2;
    while(now != 0) {
        idx += 1;
        int tmp = (now + pre) % K;
        pre = now;
        now = tmp;
    }

    int64_t ans = int64_t(idx) * (N % MOD) % MOD;

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
