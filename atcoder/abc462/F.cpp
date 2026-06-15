#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    std::string S;
    std::cin >> S;

    int K;
    std::cin >> K;

    auto diff = [](std::string s, std::string t) {
        int c = 0;
        for(int i = 0; i < 3; i++) {
            if(s[i] != t[i]) {
                c++;
            }
        }
        return c;
    };

    int N = S.size();
    std::string t = "ABC";
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1, INF));

    for(int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }

    for(int i = 3; i <= N; i++) {
        std::string s = S.substr(i - 3, 3);
        int cost = diff(s, t); 
        for(int j = 0; j <= K; j++) {
            if(s == t) {
                // if(t != "ABC" && j + 1 <= K && dp[i - 3][j + 1] != INF) {
                //     dp[i][j] = std::min(dp[i][j], dp[i - 3][j + 1] + cost); 
                // }
                dp[i][j] = std::min(dp[i][j], dp[i - 3][j]);
            } else {
                // if(t != "ABC" && dp[i - 3][j] != INF) {
                //     if((i - 5 >= 0 && S.substr(i - 5, 3) == "ABC") || (i - 4 >= 0 && S.substr(i - 4, 3) == "ABC")) {
                //         if(j + 1 <= K) {
                //             dp[i][j] = std::min(dp[i][j], dp[i - 3][j + 1] + cost);
                //         }
                //     } else {
                //         dp[i][j] = std::min(dp[i][j], dp[i - 3][j] + cost);
                //     }
                // }
                
                // -> ABC
                if((i - 5 >= 0 && S.substr(i - 5, 3) == t) || (i - 4 >= 0 && S.substr(i - 4, 3) == t)) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 3][j] + cost);
                } else if(j - 1 >= 0) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 3][j - 1] + cost);
                }

                dp[i][j] = std::min(dp[i][j], dp[i - 1][j]);
            }
        }
    } 

    std::cout << (dp[N][K] == INF ? -1 : dp[N][K]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
