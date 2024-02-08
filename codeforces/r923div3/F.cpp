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

bool dfs(std::vector<std::vector<std::array<int, 3>>>& G, std::vector<int>& color, std::vector<int>& s, 
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
        dfs(G, color, s, e, e.second, v, t, cycle); 
    } else {
        for(auto& nei : G[v]) {
            if(nei[0] != p && color[nei[0]] != 2) {
                bool ret = dfs(G, color, s, e, nei[0], v, t, cycle);
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
    dfs(G, color, s, {u, v}, u, -1, u, cycle);
    std::reverse(cycle.begin(), cycle.end());
    
    int cnt = cycle.size();
    std::cout << best << ' ' << cnt << '\n';
    for(int i = 0; i < cnt; i++) {
        std::cout << cycle[i] + 1 << " \n"[i == cnt - 1];
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
