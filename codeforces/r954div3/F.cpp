#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<std::vector<int>>& G, int v, int p, std::vector<int>& vis, std::vector<int>& tin, std::vector<int>& low, int& timer, int64_t& ans) {
    vis[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    int cnt = 1;
    for (int to : G[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (vis[to]) {
            low[v] = std::min(low[v], tin[to]);
        } else {
            int ret = dfs(G, to, v, vis, tin, low, timer, ans);
            cnt += ret;
            low[v] = std::min(low[v], low[to]);
            if (low[to] > tin[v]) {
                ans = std::max(ans, (int64_t)ret * ((int64_t)G.size() - ret));  
            }
        }
    }   
    return cnt;
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
        G[V].push_back(U);
    }

    std::vector<int> vis(N, 0);
    std::vector<int> tin(N, -1);
    std::vector<int> low(N, -1);
    int timer = 0;
    
    int64_t ans = 0;
    dfs(G, 0, -1, vis, tin, low, timer, ans);

    ans = (int64_t)N * (N - 1) / 2 - ans;
    std::cout << ans << '\n';
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
