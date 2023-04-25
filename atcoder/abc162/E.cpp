#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

LL MOD = (LL)1e9 + 7LL;

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y % 2 == 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<LL> power_n(K + 1, 0LL);
    std::vector<LL> seq_of_factor(K + 1, 0LL);

    for(int i = 1; i <= K; i++) {
        power_n[i] = q_pow(i, N);
    }

    for(int i = K; i >= 1; i--) {
        seq_of_factor[i] = power_n[K / i];

        for(int j = i + i; j <= K; j += i) {
            seq_of_factor[i] -= seq_of_factor[j];
            seq_of_factor[i] += MOD;
            seq_of_factor[i] %= MOD;
        }
    }

    LL ans = 0LL;
    for(int i = 1; i <= K; i++) {
        ans += seq_of_factor[i] * i % MOD; 
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
