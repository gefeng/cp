#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    std::vector<std::vector<int>> prefix(N + 1, std::vector<int>(K + 1, 0));
    std::vector<std::vector<int>> suffix(N + 1, std::vector<int>(K + 1, 0));
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
            if(S[i - 1] == '1') {
                prefix[i][j] = prefix[i - 1][j] + 1;
            } else {
                if(j) {
                    prefix[i][j] = prefix[i - 1][j - 1] + 1;
                }
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
            if(S[N - i] == '1') {
                suffix[i][j] = suffix[i - 1][j] + 1;
            } else {
                if(j) {
                    suffix[i][j] = suffix[i - 1][j - 1] + 1;
                }
            }
        }
    }

    for(int i = 0; i <= K; i++) {
        for(int j = 1; j <= N; j++) {
            prefix[j][i] = std::max(prefix[j][i], prefix[j - 1][i]);
            suffix[j][i] = std::max(suffix[j][i], suffix[j - 1][i]); 
        }
    }

    std::vector<int> dp(N + 1, -1);
    int freq = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            freq += 1;
        }
    }

    if(N - freq <= K) {
        dp[0] = N;
    }
    
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = i; j < N; j++) {
            if(S[j] == '1') {
                cnt += 1;
            } 

            if(cnt > K) {
                break;
            }
            
            dp[j - i + 1] = std::max(dp[j - i + 1], std::max(prefix[i][K - cnt], suffix[N - j - 1][K - cnt]));
        } 
    }

    for(int i = 1; i <= N; i++) {
        int score = 0;
        for(int j = 0; j <= N; j++) {
            if(dp[j] != -1) {
                score = std::max(score, j * i + dp[j]);
            }
        }

        std::cout << score << " \n"[i == N];
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
