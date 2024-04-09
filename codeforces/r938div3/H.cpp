#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>

constexpr int MAX = 12;

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;
    
    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }

    std::vector<std::tuple<int, int, int>> A(K);
    for(int i = 0; i < K; i++) {
        auto& [r, c, p] = A[i];
        std::cin >> r >> c >> p;
        r -= 1;
        c -= 1;
    }

    auto get_damage = [&](int t, int r) {
        int64_t damage = 0;
        auto [x, y, p] = A[t];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(G[i][j] == '#') {
                    if((int64_t)(i - x) * (i - x) + (int64_t)(j - y) * (j - y) <= r * r) {
                        damage += p;
                    }
                }
            }
        }
        return damage;
    };

    std::vector<std::vector<int64_t>> damage(K, std::vector<int64_t>(MAX + 1, 0));
    for(int i = 0; i < K; i++) {
        for(int j = 1; j <= MAX; j++) {
            damage[i][j] = get_damage(i, j);
        }
    }

    int64_t ans = 0;
    std::vector<std::vector<int64_t>> dp(K + 1, std::vector<int64_t>(1 << MAX, -1));
    dp[0][0] = 0;
    for(int i = 1; i <= K; i++) {
        for(int j = 0; j < (1 << MAX); j++) {
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
            
            if(dp[i - 1][j] != -1) {
                for(int k = 0; k < MAX; k++) {
                    if(j & (1 << k)) {
                        continue;
                    }
                    int r = k + 1;
                    int64_t x = damage[i - 1][r];
                    int nj = j | (1 << k);
                    dp[i][nj] = std::max(dp[i][nj], dp[i - 1][j] + x);
                }
            }
        }
    }

    for(int use = 1; use < (1 << MAX); use++) {
        if(dp[K][use] != -1) {
            int64_t max_damage = dp[K][use];
            int64_t extra_hp = 0;
            for(int i = 0; i < MAX; i++) {
                if(use & (1 << i)) {
                    extra_hp += (int64_t)std::pow(3, i + 1);
                }
            }

            if(max_damage >= extra_hp) {
                ans = std::max(ans, max_damage - extra_hp);
            }
        }
    }
    
    /*for(int use = 1; use < (1 << MAX); use++) {
        int tot = __builtin_popcount(use);
        std::vector<int> a(tot);
        for(int i = 0, j = 0; i < MAX; i++) {
            if(use & (1 << i)) {
                a[j++] = i + 1; 
            }
        } 

        //std::vector<std::vector<int64_t>> dp(K + 1, std::vector<int64_t>(1 << tot, -1));
        dp[0][0] = 0;
        for(int i = 1; i <= K; i++) {
            for(int j = 0; j < (1 << tot); j++) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
                
                if(dp[i - 1][j] != -1) {
                    for(int k = 0; k < tot; k++) {
                        if(j & (1 << k)) {
                            continue;
                        }

                        int r = a[k];
                        
                        int64_t x = damage[i - 1][r];
                        int nj = j | (1 << k);
                        dp[i][nj] = std::max(dp[i][nj], dp[i - 1][j] + x);
                    }
                }
            }
        }

        int64_t max_damage = dp[K][(1 << tot) - 1];
        int64_t extra_hp = 0;
        for(int r : a) {
            extra_hp += (int64_t)std::pow(3, r);
        }

        if(max_damage >= extra_hp) {
            ans = std::max(ans, max_damage - extra_hp);
        }
    }*/

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
