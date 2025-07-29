#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <ranges>

constexpr int INF = static_cast<int>(2e9);

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& dist, int v, std::vector<int>& vis, std::vector<int>& dp) {
    vis[v] = 1;
    
    dp[v] = dist[v];
    
    for(int nei : G[v]) {
        if(dist[nei] > dist[v]) {
            if(!vis[nei]) {
                dfs(G, dist, nei, vis, dp);
            }
            dp[v] = std::min(dp[v], dp[nei]);
        } else {
            dp[v] = std::min(dp[v], dist[nei]);
        }
    }
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
    }

    std::vector<int> dist(N, INF);
    std::queue<int> q;
    q.push(0);
    dist[0] = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(int nei : G[v]) {
            if(dist[nei] > dist[v] + 1) {
                dist[nei] = dist[v] + 1;
                q.push(nei);
            }
        }
    }

    std::vector<int> vis(N, 0);
    std::vector<int> dp(N, 0);
    dfs(G, dist, 0, vis, dp);

    for(int i = 0; i < N; i++) {
        std::cout << dp[i] << " \n"[i == N - 1];
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
