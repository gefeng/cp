#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    int64_t sum = 0;
    
    for(int i = 0; i < N; i++) {
        int x = A[i];
        int64_t d = 1;
        while(x) {
            x /= 10;
            d *= 10;
        }

        d %= MOD;

        ans += ((sum * d % MOD) + ((int64_t)A[i] * i % MOD)) % MOD;
        ans %= MOD;
        
        sum += A[i];
        sum %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
