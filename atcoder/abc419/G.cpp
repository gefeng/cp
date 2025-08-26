#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <queue>

void dfs(int N, std::vector<std::set<std::pair<int, int>>>& G, int v, int len, std::vector<int>& vis, std::vector<int64_t>& ans) {
    if(v == N - 1) {
        ans[len] += 1;
        return;
    }

    vis[v] = 1;

    for(auto [nei, w] : G[v]) {
        if(!vis[nei]) {
            dfs(N, G, nei, len + w, vis, ans);
        }
    }

    vis[v] = 0;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::set<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].emplace(V, 1);
        G[V].emplace(U, 1);
    }

    std::queue<int> q;
    for(int i = 1; i < N - 1; i++) {
        if(G[i].size() == 1) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        auto [p, _] = *G[v].begin();
        G[p].erase({v, 1});
        G[v].clear();
        if(p != 0 && p != N - 1 && G[p].size() == 1) {
            q.push(p);
        }
    }

    for(int i = 1; i < N - 1; i++) {
        if(G[i].size() == 2) {
            auto [u, w1] = *G[i].begin();
            auto [v, w2] = *std::next(G[i].begin());
            G[u].erase({i, w1});
            G[v].erase({i, w2});
            G[u].emplace(v, w1 + w2);
            G[v].emplace(u, w1 + w2);
            G[i].clear();
        }
    }

    std::vector<int64_t> ans(N, 0);
    std::vector<int> vis(N, 0);
    dfs(N, G, 0, 0, vis, ans);

    for(int i = 1; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
