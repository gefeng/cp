#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

constexpr int INF = static_cast<int>(2e9);

void find_bridge(std::vector<std::vector<std::pair<int, int>>>& G, int v, int p, int& t, std::vector<int>& vis, 
        std::vector<int>& min_t, std::vector<int>& is_bridge) {
    t += 1;
    min_t[v] = t;
    vis[v] = 1;
    int now = t;
    for(auto [nei, i] : G[v]) {
        if(!vis[nei]) {
            find_bridge(G, nei, v, t, vis, min_t, is_bridge);
        }
        if(nei != p) {
            min_t[v] = std::min(min_t[v], min_t[nei]);
        }
    } 

    for(auto [nei, i] : G[v]) {
        if(min_t[nei] > now) {
            is_bridge[i] = 1;
        }
    }
}

bool dfs(int N, std::vector<std::vector<std::pair<int, int>>>& G, std::vector<int>& used, int v, std::vector<int>& vis, int mark) {
    if(v == N - 1) {
        return true; 
    } 

    vis[v] = 1;
    for(auto [nei, i] : G[v]) {
        if(!vis[nei] && !used[i]) {
            if(mark) {
                used[i] = 1;
            }
            if(dfs(N, G, used, nei, vis, mark)) {
                return true;
            }
            if(mark) {
                used[i] = 0;
            }
        }
    }

    return false;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<std::pair<int, int>>> G(N);

    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, i);
        G[V].emplace_back(U, i);
    }

    std::vector<int> is_bridge(M, 0);
    std::vector<int> is_critical(M, 0);
    std::vector<int> min_t(N, INF);
    std::vector<int> vis(N, 0);
    int time = 0;
    find_bridge(G, 0, -1, time, vis, min_t, is_bridge);

    // for(int i = 0; i < N; i++) {
    //     std::cout << min_t[i] << " \n"[i == M - 1];
    // }

    std::vector<int> used(M, 0); 
    vis.assign(N, 0);
    dfs(N, G, used, 0, vis, 1);
    
    vis.assign(N, 0);
    bool exist = true;
    if(dfs(N, G, used, 0, vis, 0)) {
        exist = false;
    }

    for(int i = 0; i < M; i++) {
        if(used[i] && is_bridge[i]) {
            is_critical[i] = 1;
        }
    }

    std::vector<int> nxt_e(N, INF);
    std::vector<int> nxt_d(N, INF);
    std::vector<int> pre_e(N, INF);
    std::vector<int> pre_d(N, INF);
    auto bfs = [&](int st, std::vector<int>& a, std::vector<int>& b) {
        std::queue<std::tuple<int, int, int>> q;
        vis.assign(N, 0);

        q.emplace(st, INF, -1);
        vis[st] = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto [v, d, e] = q.front(); 
                q.pop();

                for(auto [nei, i] : G[v]) {
                    if(!vis[nei]) {
                        vis[nei] = 1;
                        if(is_critical[i]) {
                            a[nei] = i;
                            a[v] = i;
                            b[nei] = 0;
                            b[v] = 0;
                            q.emplace(nei, 0, i);
                        } else {
                            int nd = d == INF ? d : d + 1;
                            a[nei] = e;
                            b[nei] = nd;
                            q.emplace(nei, nd, e);
                        }
                    }
                }
            }
        }
    };

    bfs(0, pre_e, pre_d);
    bfs(N - 1, nxt_e, nxt_d);

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int V;
        std::cin >> V;
        V -= 1;
        if(!exist) {
            std::cout << -1 << " \n"[i == Q - 1];
            continue;
        }
        
        if(pre_d[V] == INF && nxt_d[V] == INF) {
            std::cout << -1 << " \n"[i == Q - 1];
        } else {
            if(pre_d[V] == nxt_d[V]) {
                std::cout << std::min(pre_e[V], nxt_e[V]) + 1 << " \n"[i == Q - 1];
            } else {
                std::cout << (pre_d[V] < nxt_d[V] ? pre_e[V] + 1 : nxt_e[V] + 1) << " \n"[i == Q - 1];
            }
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
