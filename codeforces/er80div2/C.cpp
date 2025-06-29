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
    int N, M;
    std::cin >> N >> M;

    std::vector<int64_t> da(N + 1, 0);
    {
        std::vector<int64_t> psum(N + 2, 0);
        for(int i = 1; i <= N; i++) {
            da[i] = 1;
            psum[i + 1] = (psum[i] + da[i]) % MOD;
        }

        for(int i = 1; i < M; i++) {
            std::vector<int64_t> n_da(N + 1, 0);
            for(int j = 1; j <= N; j++) {
                n_da[j] = psum[j + 1]; 
            }
            da = std::move(n_da);
            for(int j = 1; j <= N; j++) {
                psum[j + 1] = (psum[j] + da[j]) % MOD;
            }
        }
    }

    std::vector<int64_t> db(N + 1);
    for(int i = 1; i <= N; i++) {
        std::vector<int64_t> ds(N + 1, 0);
        std::vector<int64_t> psum(N + 2, 0);
        for(int j = i; j <= N; j++) {
            ds[j] = 1;
            psum[j + 1] = (psum[j] + ds[j]) % MOD;
        }

        for(int j = 1; j < M; j++) {
            std::vector<int64_t> n_ds(N + 1, 0);
            for(int k = i; k <= N; k++) {
                n_ds[k] += (psum[N + 1] - psum[k] + MOD) % MOD;
                n_ds[k] %= MOD;
            }

            ds = std::move(n_ds);
            for(int k = i; k <= N; k++) {
                psum[k + 1] = (psum[k] + ds[k]) % MOD;
            }
        }
        db[i] = psum[N + 1];
    }

    int64_t ans = 0;
    for(int a = 1; a <= N; a++) {
        ans += da[a] * db[a] % MOD;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
