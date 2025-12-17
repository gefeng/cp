#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 10000;
constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = INF;
    std::vector<int> dp(N + 1, INF);
    std::vector<std::vector<int>> cost(N, std::vector<int>(N, 0));
    
    for(int i = 0; i < N; i++) {
        int now = 0;
        int sum = 0;
        for(int j = i; j < N; j++) {
            if(i == j) {
                cost[i][j] = A[j] == 0 ? 0 : 1;
                now = A[j];
            } else {
                if(now == 0) {
                    cost[i][j] = sum + (A[j] == 0 ? 0 : 1);
                    now = A[j];
                } else {
                    sum += 1;
                    cost[i][j] = (A[j] ^ now) == 0 ? sum : sum + 1;
                    now ^= A[j];
                }
            }
        }
    }
    
    dp[0] = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] = std::min(dp[i], dp[j] + cost[j][i - 1]);
        }
    }

    std::cout << dp[N] << '\n';
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
