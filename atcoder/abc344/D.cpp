#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

void run_case() {
    std::string T;
    std::cin >> T;

    int N;
    std::cin >> N;
    
    std::vector<std::vector<std::string>> A(N);
    for(int i = 0; i < N; i++) {
        int M;
        std::cin >> M;
        
        for(int j = 0; j < M; j++) {
            std::string S;
            std::cin >> S;

            A[i].push_back(S);
        }
    }

    int n = T.size();
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(n + 1, INF));
    
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++) {
        dp[i][0] = 0;
        for(int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j]; 
            
            for(std::string& s : A[i - 1]) {
                // "aaabc"
                // "abc"
                int m = s.size();
                if(m <= j && s == T.substr(j - m, m) && dp[i - 1][j - m] != INF) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - m] + 1);  
                }
            }
        }
    }

    int ans = INF;
    for(int i = 1; i <= N; i++) {
        ans = std::min(ans, dp[i][n]);
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
