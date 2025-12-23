#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::ranges::sort(B);
    
    std::vector<int64_t> psum(M + 1, 0);
    for(int i = 0; i < M; i++) {
        psum[i + 1] = (psum[i] + B[i]) % MOD;
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int j = std::lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        ans += static_cast<int64_t>(j) * A[i] % MOD;
        ans %= MOD;
        ans -= psum[j];
        ans += MOD;
        ans %= MOD;
        
        ans += (psum[M] - psum[j] + MOD) % MOD;
        ans %= MOD;
        ans -= static_cast<int64_t>(M - j) * A[i] % MOD;
        ans += MOD;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
