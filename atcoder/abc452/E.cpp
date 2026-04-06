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
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::vector<int64_t> psum1(N + 1, 0);
    std::vector<int64_t> psum2(N + 1, 0);

    for(int i = 0; i < N; i++) {
        psum1[i + 1] = (psum1[i] + A[i]) % MOD;
        psum2[i + 1] = (psum2[i] + static_cast<int64_t>(A[i]) * (i + 1)) % MOD;
    }

    int64_t ans = 0;
    for(int j = 1; j <= M; j++) {
        ans += B[j - 1] * psum2[N] % MOD;
        ans %= MOD;

        int64_t k = 0;
        while(true) {
            int l = std::max(static_cast<int64_t>(1), k * j);
            int r = std::min(static_cast<int64_t>(N), (k + 1) * j - 1);
            if(l > N) {
                break;
            }

            ans -= (B[j - 1] * ((psum1[r] - psum1[l - 1] + MOD) % MOD) % MOD) * (k * j % MOD) % MOD;
            ans += MOD;
            ans %= MOD;
            k++;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
