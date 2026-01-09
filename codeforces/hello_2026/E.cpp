#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(A[0] > 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<std::vector<int>> gcd_lookup(M + 1, std::vector<int>(M + 1, 0));
    for(int i = 1; i <= M; i++) {
        for(int j = i; j <= M; j++) {
            gcd_lookup[i][j] = gcd(i, j);
        }
    }

    std::vector<std::vector<int>> divisors(M + 1);
    for(int i = 1; i <= M; i++) {
        for(int f = 1; f * f <= i; f++) {
            if(i % f == 0) {
                divisors[i].push_back(f);
                if(i / f != f) {
                    divisors[i].push_back(i / f);
                }
            }
        }
    }

    std::vector<int64_t> dp(M + 1, 0);
    dp[1] = 1;
    for(int i = 1; i < N; i++) {
        std::vector<int64_t> ndp(M + 1, 0);
        if(A[i] == 0) {
            for(int j = 1; j <= M; j++) {
                for(int d : divisors[j]) {
                    int x = j + d;
                    if(x <= M && x >= 1 && gcd_lookup[j][x] == d) {
                        ndp[x] += dp[j];
                        ndp[x] %= MOD;
                    }
                }
            }
        } else {
            for(int j = 1; j <= M; j++) {
                for(int d : divisors[j]) {
                    int x = j + d;
                    if(x == A[i] && gcd_lookup[j][x] == d) {
                        ndp[x] += dp[j];
                        ndp[x] %= MOD;
                    }
                }
            }
        }
        dp = std::move(ndp);
    }

    int64_t ans = 0;
    for(int i = 1; i <= M; i++) {
        ans += dp[i];
        ans %= MOD;
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
