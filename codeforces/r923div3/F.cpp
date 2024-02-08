#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct dsu {
    int n;
    std::vector<int> p;
    std::vector<int> w;

    dsu(int n) : n(n) {
        p.resize(n, -1);
        w.resize(n, 1);
    }

    int find(int i) {
        if(p[i] < 0) {
            return i;
        }
        return p[i] = find(p[i]);
    }

    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) {
            return;
        }
        if(w[x] >= w[y]) {
            p[y] = x;
            w[x] += w[y];
        } else {
            p[x] = y;
            w[y] += w[x];
        }
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }
};

void dfs1(std::vector<std::vector<std::array<int, 3>>>& G, std::vector<int>& color, std::vector<std::pair<int, int>>& s, int v, int p, int e, std::vector<int>& incycle) {
    if(color[v] == 1) {
        int cur_v = p;
        int cur_e = e;
        while(true) {
            if(incycle[cur_e]) {
                break;
            }
            incycle[cur_e] = 1;
            if(cur_v == v) {
                break;
            }
            cur_e = s[cur_v].second;
            cur_v = s[cur_v].first;
        }
        return;
    }

    color[v] = 1;
    s[v] = {p, e};

    for(auto& nei : G[v]) {
        if(nei[0] != p && color[nei[0]] != 2) {
            dfs1(G, color, s, nei[0], v, nei[2], incycle);
        } 
    }

    color[v] = 2;
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
                return a[2] > b[2];
            });

    dsu uf(N);
    int u = 0;
    int v = 0;
    int best = 0;
    for(auto& e : E) {
        if(uf.same(e[0], e[1])) {
            u = e[0];
            v = e[1];
            best = e[2];
        } else {
            uf.unite(e[0], e[1]);
        }
    }

    
    std::vector<int> color(N, 0);
    std::vector<int> s(N);
    std::vector<int> cycle;
    dfs2(G, color, s, {u, v}, u, -1, u, cycle);
    std::reverse(cycle.begin(), cycle.end());
    
    int cnt = cycle.size();
    std::cout << best << ' ' << cnt << '\n';
    for(int i = 0; i < cnt; i++) {
        std::cout << cycle[i] + 1 << " \n"[i == cnt - 1];
    }

    /*std::vector<int> incycle(M, 0);
    std::vector<int> color(N, 0);
    std::vector<std::pair<int, int>> s(N);
    for(int i = 0; i < N; i++) {
        if(color[i] == 0) {
            dfs1(G, color, s, i, -1, -1, incycle);
        }
    }

    for(auto& e : E) {
        if(incycle[e[3]]) {
            color = std::vector<int>(N, 0);
            std::vector<int> cycle;
            std::vector<int> stk(N);
            dfs2(G, color, stk, std::pair<int, int>(e[0], e[1]), e[0], -1, e[0], cycle);
            std::reverse(cycle.begin(), cycle.end());
            
            int cnt = cycle.size();
            std::cout << e[2] << ' ' << cnt << '\n';
            for(int i = 0; i < cnt; i++) {
                std::cout << cycle[i] + 1 << " \n"[i == cnt - 1];
            }
            return;
        }
    }*/
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
