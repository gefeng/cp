#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <queue>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - i; j++) {
            std::cin >> A[i][i + j];
        }
    }

    std::vector<std::vector<int>> dp(N + 1);
    dp[0].push_back(0);

    for(int i = 1; i <= N; i++) {
        std::priority_queue<std::tuple<int, int, int, int>> pq;
        pq.emplace(A[0][i - 1], -1, 0, 1);
        for(int j = 1; j < i; j++) {
            pq.emplace(dp[j - 1][0] + A[j][i - 1], j - 1, 0, 1);
        }

        pq.emplace(dp[i - 1][0], i - 1, 0, 0);

        while(!pq.empty() && dp[i].size() < K) {
            auto [v, p1, p2, paint] = pq.top(); 
            pq.pop();

            dp[i].push_back(v);

            if(p1 != -1 && p2 + 1 < dp[p1].size()) {
                int nv = dp[p1][p2 + 1] + (paint ? A[p1 + 1][i - 1] : 0);
                pq.emplace(nv, p1, p2 + 1, paint); 
            }
        }
    }

    for(int i = 0; i < K; i++) {
        std::cout << dp[N][i] << " \n"[i == K - 1];
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
