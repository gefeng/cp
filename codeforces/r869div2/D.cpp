#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

void dfs1(std::vector<std::vector<int>>& G, int t, int v, int d, std::vector<int>& vis) {
    for(int nei : G[v]) {
        if(nei == t) {
            if(d > 1) {
                vis[t] = std::min(vis[t], d + 1);
            } 
        } else {
            if(vis[nei] == 0) {
                vis[nei] = 1; 
                dfs1(G, t, nei, d + 1, vis);
            }
        }
    }
}

bool dfs2(std::vector<std::vector<int>>& G, int tv, int td, int v, int d, std::vector<int>& vis, std::vector<int>& cycle) {
    vis[v] = 1;
    cycle.push_back(v);

    for(int nei : G[v]) {
        if(nei == tv) {
            if(d + 1 == td) {
                return true;
            }
        } else {
            if(vis[nei] == 0) {
                if(dfs2(G, tv, td, nei, d + 1, vis, cycle)) {
                    return true;
                }
            }
        }
    }

    cycle.pop_back();
    return false;
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

    for(int i = 0; i < N; i++) {
        std::vector<int> cycle;
        std::vector<int> vis(N, 0);
        vis[i] = INF;

        dfs1(G, i, i, 0, vis);

        if(vis[i] == INF) {
            continue;
        }

        int t = vis[i];
        vis = std::vector<int>(N, 0);
        dfs2(G, i, t, i, 0, vis, cycle);

        int start = cycle[1];
        int end = cycle.back();
        
        int extra1 = -1;
        int extra2 = -1;
        for(int nei : G[i]) {
            if(nei != start && nei != end) {
                if(extra1 == -1) {
                    extra1 = nei;
                } else if(extra2 == -1) {
                    extra2 = nei;
                }
            }
        } 

        if(extra2 != -1) {
            int sz = t + 2;
            std::cout << "YES\n" << sz << '\n';
            
            for(int j = 0; j < t; j++) {
                if(j == t - 1) {
                    std::cout << cycle[j] + 1 << ' ' << i + 1 << '\n';
                } else {
                    std::cout << cycle[j] + 1 << ' ' << cycle[j + 1] + 1 << '\n';
                }
            }

            std::cout << i + 1 << ' ' << extra1 + 1 << '\n';
            std::cout << i + 1 << ' ' << extra2 + 1 << '\n';

            return;
        }
    }

    std::cout << "NO" << '\n';
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
