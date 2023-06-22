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
    int N;
    std::cin >> N;

    std::vector<int> A(N + 2, 0);
    A[N + 1] = N + 1;

    for(int i = 0; i < N; i++) {
        std::cin >> A[i + 1];
    } 
    
    std::vector<std::vector<int>> dp(N + 2, std::vector<int>(N + 1, INF));
    for(int i = 0; i <= N; i++) {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= N + 1; i++) {
        for(int j = 0; j <= N; j++) {
            if(A[i] > A[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            }

            if(j) {
                for(int k = 0; k < i - 1; k++) {
                    if(A[k] < A[i]) {
                        dp[i][j] = std::min(dp[i][j], dp[k][j - 1] + i - k - 1);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        std::cout << dp[N + 1][i] << " \n"[i == N];
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
