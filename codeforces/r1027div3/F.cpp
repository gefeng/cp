#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>

constexpr int INF = int(2e9);

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int64_t X, Y, K;
    std::cin >> X >> Y >> K;

    if(X == Y) {
        std::cout << 0 << '\n';
        return;
    }

    auto count = [&](int64_t k, std::vector<int64_t>& divisors) {
        int n = divisors.size();

        if(n == 0) {
            return INF;
        }

        std::vector<int> dp(n, INF);
         
        int p = -1;
        for(int i = 0; i < n; i++) {
            std::vector<int> n_dp(dp);
            if(divisors[i] == k) {
                p = i;
            }
            if(divisors[i] <= K) {
                n_dp[i] = divisors[i] == 1 ? 0 : 1;
            }
            for(int j = 0; j < n; j++) {
                if(divisors[i] % divisors[j] == 0 && divisors[i] / divisors[j] <= K && dp[j] != INF) {
                    n_dp[i] = std::min(n_dp[i], dp[j] + 1);
                }
            }
            dp = std::move(n_dp);
        } 
        
        return p == -1 ? INF : dp[p];
    };

    auto solve = [&](int64_t x, int64_t y) {
        int64_t k = x / y;
        if(k == 1) {
            return 0;
        }
        if(k <= K) {
            return 1;
        }

        std::vector<int64_t> divisors;
        for(int64_t f = 1; f * f <= k; f++) {
            if(k % f == 0) {
                divisors.push_back(f);
                if(k / f != f) {
                    divisors.push_back(k / f);
                }
            }
        }

        std::sort(divisors.begin(), divisors.end());
        return count(k, divisors);
    };

    int ans = INF;
    if(Y <= K && X <= K) {
        ans = 2;
    }

    int64_t g = gcd(X, Y);

    int cnt_1 = solve(X, g);
    if(cnt_1 != INF) {
        int cnt_2 = solve(Y, g);
        if(cnt_2 != INF) {
            ans = std::min(ans, cnt_1 + cnt_2);
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
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
