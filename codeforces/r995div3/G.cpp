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
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<std::pair<int, char>> A(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first -= 1;
    }
    
    std::vector<std::vector<int>> dist(N, std::vector<int>(N, 0));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int init = 1;
            if(i == j) {
                for(auto [k, t] : A) {
                    if(k == i && t == '+') {
                        init += 1; 
                    }
                }
            } else {
                int now = 1;
                for(auto [k, t] : A) {
                    if(k == i) {
                        if(t == '+') {
                            now -= 1;
                        } 
                    } else if(k == j) {
                        if(t == '-') {
                            now += 1;
                        }
                    }
                    if(now == 0) {
                        init += 1;
                        now = 1;
                    }
                }
            }
            dist[i][j] = init;
        }
    }

    std::vector<std::vector<int>> dp(1 << N, std::vector<int>(N, INF));
    for(int i = 0; i < N; i++) {
        dp[1 << i][i] = 1;
    }

    for(int i = 1; i < (1 << N); i++) {
        for(int j = 0; j < N; j++) {
            if((i & (1 << j)) && dp[i][j] != INF) {
                for(int k = 0; k < N; k++) {
                    if(i & (1 << k)) {
                        continue;
                    }
                    
                    int ni = i ^ (1 << k);
                    dp[ni][k] = std::min(dp[ni][k], dp[i][j] + dist[j][k]);
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < N; i++) {
        ans = std::min(ans, dp[(1 << N) - 1][i] + dist[i][i] - 1);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
