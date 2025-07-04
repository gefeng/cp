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
    int N;
    std::cin >> N;

    int64_t ans = 1;
    int64_t no_cycle = 1;
    for(int i = 1; i <= N; i++) {
        ans *= i;
        ans %= MOD;
    }

    for(int i = 0; i < N - 1; i++) {
        no_cycle *= 2; 
        no_cycle %= MOD;
    }

    ans = (ans - no_cycle + MOD) % MOD;
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
