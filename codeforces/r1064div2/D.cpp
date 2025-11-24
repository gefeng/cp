#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    std::vector<int> a;
    int max_f = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        a.push_back(i - j);
        max_f = std::max(max_f, i - j);
    }

    int n = a.size();
    int64_t ans = 0;
    std::vector<int64_t> dp1(2, 0);
    dp1[0] = 1;
    for(int i = 0; i < n; i++) {
        std::vector<int64_t> ndp1(dp1);
        if(a[i] == max_f) {
            ndp1[1] += dp1[0] * a[i] % MOD;
            ndp1[1] %= MOD;
            ndp1[1] += dp1[1] * a[i] % MOD;
            ndp1[1] %= MOD;
        } else {
            for(int j = 0; j < 2; j++) {
                ndp1[j] += dp1[j] * a[i] % MOD;
                ndp1[j] %= MOD;
            }
        }
        dp1 = std::move(ndp1);
    }
    ans = dp1[1];

    std::vector<int64_t> dp2(max_f + 1, 0);
    dp2[0] = 1;
    for(int i = 0; i < n; i++) {
        std::vector<int64_t> ndp2(dp2);
        if(a[i] != max_f) {
            for(int j = 0; j <= max_f; j++) {
                int nj = std::min(max_f, j + a[i]);
                ndp2[nj] += dp2[j] * a[i] % MOD;
                ndp2[nj] %= MOD;
            }
        }
        dp2 = std::move(ndp2);
    }
    ans += dp2[max_f];
    ans %= MOD;
    
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
