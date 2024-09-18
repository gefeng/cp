#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<std::pair<int, int>>> a(N, std::vector<std::pair<int, int>>(5, {0, -1}));
    std::string T = "narek";
    
    for(int i = 0; i < N; i++) {
        std::string& s = A[i];
        
        for(int st = 0; st < 5; st++) {
            int score = 0;
            int k = st;
            for(int j = 0; j < M; j++) {
                if(s[j] == T[k]) {
                    if(k == 4) {
                        score += 5;
                    }
                    k = (k + 1) % 5; 
                } else {
                    if(T.find(s[j]) != std::string::npos) {
                        score -= 1;
                    }
                }
            }
            a[i][st] = {score, k}; 
        }
    }

    std::vector<std::vector<int>> dp(N, std::vector<int>(5, -INF));
    int ans = 0;
    std::vector<int> max_v(5, -INF);
    for(int i = 0; i < N; i++) {
        dp[i][0] = 0;
        dp[i][a[i][0].second] = std::max(dp[i][a[i][0].second], a[i][0].first);

        for(int k = 0; k < 5; k++) {
            auto [score, nxt] = a[i][k];
            if(max_v[k] != -INF) {
                dp[i][nxt] = std::max(dp[i][nxt], max_v[k] + score);
            }
        }

        for(int k = 0; k < 5; k++) {
            max_v[k] = std::max(max_v[k], dp[i][k]);
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 5; j++) {
            if(dp[i][j] != -INF) {
                if(j != 0) {
                    dp[i][j] -= j;
                }
                ans = std::max(ans, dp[i][j]);
            }
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
