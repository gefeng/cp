#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<std::vector<int>> G(N);
    std::vector<std::vector<int>> R(N);
    std::vector<int> degree(N, 0);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        R[V].push_back(U);
        degree[U] += 1;
    }

    std::vector<std::vector<int>> dp(2, std::vector<int>(N, 1));
    std::queue<std::pair<int, int>> q;

    for(int i = 0; i < Q; i++) {
        int T, X;
        std::cin >> T >> X;
        X -= 1;

        if(T == 1) {
            if(dp[0][X]) {
                q.emplace(X, 0);
                dp[0][X] = 0;
            }
            if(dp[1][X]) {
                q.emplace(X, 1);
                dp[1][X] = 0;
            }
            
            while(!q.empty()) {
                auto [v, who] = q.front();
                q.pop();

                if(who == 1) {
                    for(int nei : R[v]) {
                        if(--degree[nei] == 0 && dp[0][nei]) {
                            dp[0][nei] = 0;
                            q.emplace(nei, 0);
                        }
                    }
                } else {
                    for(int nei : R[v]) {
                        if(dp[1][nei]) {
                            dp[1][nei] = 0;
                            q.emplace(nei, 1);
                        }
                    }
                }
            }
        } else {
            std::cout << (dp[0][X] ? "Yes" : "No") << '\n';
        }
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
