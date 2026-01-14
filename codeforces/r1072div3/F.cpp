#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<std::vector<int>>& dp) {
    dp[1][v] = 1;

    if(v != 0 && G[v].size() == 1) {
        return;
    }

    std::array<int, 3> now{1, 0, 0};
    for(int nei : G[v]) {
        if(p == nei) {
            continue;
        }
        dfs(G, nei, v, dp);
        
        std::array<int, 3> nxt{};
        for(int i = 0; i < 3; i++) {
            if(now[i]) {
                for(int j = 0; j < 3; j++) {
                    if(dp[j][nei]) {
                        nxt[(i + j) % 3] = 1;
                    }
                }
            }
        } 
        now = std::move(nxt);
    }

    dp[0][v] = now[0];
    dp[2][v] = now[2];
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<std::vector<int>> dp(3, std::vector<int>(N, 0));
    
    dfs(G, 0, -1, dp);
    
    std::cout << (dp[0][0] ? "Yes" : "No") << '\n';
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
