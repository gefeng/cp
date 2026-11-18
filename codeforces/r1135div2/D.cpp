#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
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
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int, int>> B(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> B[i].first >> B[i].second;
        B[i].first--;
    }

    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    std::vector<int64_t> psum(N + 1, 0);
    std::map<int64_t, std::vector<int>> m1;
    std::map<int64_t, std::vector<int>> m2;
    int64_t prefix = 0;
    int64_t suffix = 0;
    for(int i = 0; i < N; i++) {
        prefix += A[i];
        suffix += A[N - 1 - i];
        m1[prefix - suffix].push_back(i + 1);
        m2[suffix - prefix].push_back(i + 1);
        
        psum[i + 1] = psum[i] + (prefix == suffix ? 1 : 0);
    }

    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    for(int i = 0; i < Q; i++) {
        auto [p, d] = B[i];
        int f = psum[N];
        int64_t res = 0;
        if(p == N - p - 1) {
        } else if(p < N - p - 1) {
            f -= psum[N - p - 1] - psum[p];
            if(m2.find(d) != m2.end()) {
                f += std::upper_bound(m2[d].begin(), m2[d].end(), N - p - 1) - std::lower_bound(m2[d].begin(), m2[d].end(), p + 1);
            }
        } else {
            f -= psum[p] - psum[N - p - 1];
            if(m1.find(d) != m1.end()) {
                f += std::upper_bound(m1[d].begin(), m1[d].end(), p) - std::lower_bound(m1[d].begin(), m1[d].end(), N - p);
            }
        }

        if(f >= M) {
            res = (fact[f - 1] * invf[M - 1] % MOD) * invf[f - M] % MOD;
        }
        std::cout << res << '\n';
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
