#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> freq(N + 2, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        freq[A[i]] += 1;
    }

    std::vector<int64_t> p_2(N + 2, 1);
    for(int i = 1; i <= N + 1; i++) {
        p_2[i] = p_2[i - 1] * 2 % MOD;
    }
    

    std::vector<int64_t> dp_0(N + 2, 0);
    std::vector<int64_t> dp_1(N + 2, 0);
    dp_0[0] = 1;
    for(int i = 1; i <= N + 1; i++) {
        dp_0[i] = dp_0[i - 1] * ((p_2[freq[i - 1]] - 1 + MOD) % MOD) % MOD;
    } 

    for(int i = 1; i <= N + 1; i++) {
        dp_1[i] = dp_1[i - 1] * ((p_2[freq[i - 1]] - 1 + MOD) % MOD) % MOD;
        dp_1[i] += dp_0[i - 1];
        dp_1[i] %= MOD;
    } 

    int64_t ans = 0;
    int64_t cnt_subset = 1;
    for(int i = N + 1; i >= 1; i--) {
        int64_t cnt = i > 1 ? dp_1[i] * cnt_subset % MOD : dp_1[i] * ((cnt_subset - 1 + MOD) % MOD) % MOD;
        ans += cnt * i % MOD;
        ans %= MOD;
        cnt_subset *= p_2[freq[i]];
        cnt_subset %= MOD;
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
