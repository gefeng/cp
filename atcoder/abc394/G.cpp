#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};
constexpr int LOG = 20;
constexpr int INF = int(2e9);

struct E {
    int u;
    int v;
    int w;
    E(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}

    bool operator < (const E& other) const {
        return w > other.w;
    }
};

struct DSU {
    int n;
    std::vector<int> p;
    std::vector<int> w;

    DSU(int _n) : n(_n), p(n, -1), w(n, 1) {}

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

void build(std::vector<std::vector<std::pair<int, int>>>& g, int v, int p, std::vector<int>& depth, std::vector<std::vector<int>>& parent, std::vector<std::vector<int>>& min_w) {
    depth[v] = p == -1 ? 0 : depth[p] + 1;
    for(int i = 1; i < LOG; i++) {
        if(parent[i - 1][v] != -1) {
            parent[i][v] = parent[i - 1][parent[i - 1][v]];
            min_w[i][v] = std::min(min_w[i - 1][v], min_w[i - 1][parent[i - 1][v]]);
        }
    }
    
    for(auto [nei, w] : g[v]) {
        if(nei == p) {
            continue;
        }
        parent[0][nei] = v;
        min_w[0][nei] = w;
        build(g, nei, v, depth, parent, min_w);
    }
}

void run_case() {
    int H, W;
    std::cin >> H >> W;
    
    std::vector<std::vector<int>> A(H, std::vector<int>(W, 0));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<E> edges;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            for(int d = 0; d < 4; d++) {
                int ni = i + DR[d];
                int nj = j + DC[d];
                if(ni >= 0 && nj >= 0 && ni < H && nj < W) {
                    edges.emplace_back(i * W + j, ni * W + nj, std::min(A[i][j], A[ni][nj]));
                }
            }
        } 
    }

    std::sort(edges.begin(), edges.end());
    
    int n = H * W;
    DSU uf(n);
    std::vector<std::vector<std::pair<int, int>>> g(n);
    for(const auto& e : edges) {
        if(uf.same(e.u, e.v)) {
            continue;
        }
        uf.unite(e.u, e.v);
        g[e.u].emplace_back(e.v, e.w);
        g[e.v].emplace_back(e.u, e.w);
    }

    std::vector<int> depth(n, 0);
    std::vector<std::vector<int>> parent(LOG, std::vector<int>(n, -1));
    std::vector<std::vector<int>> min_w(LOG, std::vector<int>(n, INF));
    build(g, 0, -1, depth, parent, min_w);
    
    // lca 
    auto query = [&](int x, int y) {
        int w = INF;
        if(depth[x] < depth[y]) {
            std::swap(x, y);
        }

        for(int i = LOG - 1; i >= 0; i--) {
            if(parent[i][x] != -1 && depth[parent[i][x]] >= depth[y]) {
                w = std::min(w, min_w[i][x]);
                x = parent[i][x];
            }
        }

        if(x == y) {
            return w;
        }
        
        for(int i = LOG - 1; i >= 0; i--) {
            if(parent[i][x] == parent[i][y]) {
                continue;
            }
            w = std::min(w, min_w[i][x]);
            w = std::min(w, min_w[i][y]);
            x = parent[i][x];
            y = parent[i][y];
        }
        w = std::min(w, min_w[0][x]);
        w = std::min(w, min_w[0][y]);
        return w;
    };

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int X_1, Y_1, H_1, X_2, Y_2, H_2;
        std::cin >> X_1 >> Y_1 >> H_1 >> X_2 >> Y_2 >> H_2;
        
        X_1 -= 1;
        Y_1 -= 1;
        X_2 -= 1;
        Y_2 -= 1;
        
        int w = query(X_1 * W + Y_1, X_2 * W + Y_2);

        std::cout << H_1 + H_2 - 2 * std::min(w, std::min(H_1, H_2)) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
