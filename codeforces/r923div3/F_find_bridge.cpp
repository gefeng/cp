#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs1(std::vector<std::vector<std::array<int, 3>>>& G, int v, int p, std::vector<int>& tin, std::vector<int>& low, int& timer, std::vector<int>& is_bridge) {
    tin[v] = timer++;
    low[v] = tin[v];

    for(auto& nei : G[v]) {
        if(nei[0] == p) {
            continue;
        }

        if(tin[nei[0]] == -1) {
            dfs1(G, nei[0], v, tin, low, timer, is_bridge);
            low[v] = std::min(low[v], low[nei[0]]);
            if(low[nei[0]] > tin[v]) {
                is_bridge[nei[2]] = 1; 
            }
        } else {
            low[v] = std::min(low[v], tin[nei[0]]);
        }
    }
}

bool dfs2(std::vector<std::vector<std::array<int, 3>>>& G, std::vector<int>& color, std::vector<int>& s, 
        std::pair<int, int> e, int v, int p, int t, std::vector<int>& cycle) {
    if(v == t && p != -1) {
        int cur = p;
        while(cur != t) {
            cycle.push_back(cur);
            cur = s[cur];
        }
        cycle.push_back(t);
        return true;
    }
    if(color[v] == 1) {
        return false;
    }

    s[v] = p;
    color[v] = 1;
    if(p == -1) {
        dfs2(G, color, s, e, e.second, v, t, cycle); 
    } else {
        for(auto& nei : G[v]) {
            if(nei[0] != p && color[nei[0]] != 2) {
                bool ret = dfs2(G, color, s, e, nei[0], v, t, cycle);
                if(ret) {
                    return true;
                }
            }
        }
    }

    color[v] = 2;
    return false;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<std::array<int, 3>>> G(N);
    std::vector<std::array<int, 4>> E(M);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].push_back({V, W, i});
        G[V].push_back({U, W, i});
        E[i] = {U, V, W, i};
    }

    std::sort(E.begin(), E.end(), [](const auto& a, const auto& b) {
                return a[2] < b[2];
            });

    std::vector<int> is_bridge(M, 0);
    std::vector<int> tin(N, -1);
    std::vector<int> low(N, -1);

    for(int i = 0; i < N; i++) {
        if(tin[i] == -1) {
            int timer = 0;
            dfs1(G, i, -1, tin, low, timer, is_bridge);
        }
    }

    for(auto& e : E) {
        if(!is_bridge[e[3]]) {
            std::vector<int> color(N, 0);
            std::vector<int> s(N);
            std::vector<int> cycle;
            dfs2(G, color, s, {e[0], e[1]}, e[0], -1, e[0], cycle);
            std::reverse(cycle.begin(), cycle.end());
            
            int cnt = cycle.size();
            std::cout << e[2] << ' ' << cnt << '\n';
            for(int i = 0; i < cnt; i++) {
                std::cout << cycle[i] + 1 << " \n"[i == cnt - 1];
            }
            return;
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
