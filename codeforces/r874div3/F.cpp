#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = (LL)1e9 + 7LL;

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y & 1LL) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1LL;
    }

    return res;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    std::vector<std::pair<int, int>> v;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }

        v.emplace_back(A[j], i - j);
    }

    int sz = v.size();
    std::vector<LL> prod(sz + 1, 1LL);
    std::vector<LL> fact(N + 1, 1LL);
    std::vector<LL> invf(N + 1, 1LL);

    for(int i = 2; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    for(int i = 2; i <= N; i++) {
        invf[i] = q_pow(fact[i], MOD - 2LL);
    }

    auto cmp = [](int a, std::pair<int, int> b) {
        return a < b.first;
    };
    
    LL ans = 0LL;
    for(int i = 0; i < sz; i++) {
        int x = v[i].first;
        int f = v[i].second;

        if(M == 1) {
            ans += f;
            ans %= MOD;
            continue;
        }
        
        auto it = std::upper_bound(v.begin(), v.begin() + i, x - M, cmp);

        int j = it - v.begin();
        if(i - j >= M - 1) {
            LL pb = (fact[i - j] * invf[i - j - M + 1] % MOD) * invf[M - 1] % MOD;
            LL cnt = ((pb * f % MOD) * prod[i] % MOD) * q_pow(prod[j], MOD - 2LL) % MOD;

            ans += cnt;
            ans %= MOD;
        }

        if(i) {
            prod[i + 1] = prod[i] * f % MOD;
        } else {
            prod[i + 1] = f;
        }
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
