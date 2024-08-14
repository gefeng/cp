#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = int(2e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        if(A[i].first > A[i].second) {
            std::swap(A[i].first, A[i].second);
        }
    } 

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1, INF));
    for(int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= K; j++) {
            dp[i + 1][j] = std::min(dp[i + 1][j], dp[i][j]);
            
            if(dp[i][j] != INF) {
                int s = A[i].first + A[i].second;
                int c = 0;
                for(int k = 1, a = A[i].first, b = A[i].second; k <= s; k++) {
                    if(a > b) {
                        std::swap(a, b);
                    }
                    c += a;
                    b -= 1;
                    if(k != s - 1) {
                        dp[i + 1][std::min(K, j + k)] = std::min(dp[i + 1][std::min(K, j + k)], dp[i][j] + c);
                    }
                }
            }
        }
    }

    std::cout << (dp[N][K] == INF ? -1 : dp[N][K]) << '\n';
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
