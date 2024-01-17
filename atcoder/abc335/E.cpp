#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = 2e9;

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

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> vs;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        vs.push_back(i);
    }

    std::vector<std::vector<int>> G(N);
    std::vector<std::pair<int, int>> E(M);
    dsu uf(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        if(A[U] == A[V]) {
            uf.unite(U, V);
        }

        E[i] = {U, V};
    }

    for(auto [u, v] : E) {
        if(!uf.same(u, v)) {
            u = uf.find(u);
            v = uf.find(v);
            if(A[u] > A[v]) {
                G[v].push_back(u);
            } else {
                G[u].push_back(v);
            }
        }
    }

    std::sort(vs.begin(), vs.end(), [&](const auto& a, const auto& b) {
                return A[a] < A[b];
            });

    std::vector<int> dp(N, -INF);
    dp[uf.find(0)] = 1;
    for(int i = 0; i < N; i++) {
        int v = uf.find(vs[i]);
        if(dp[v] == -INF) {
            continue;
        }
        for(int u : G[v]) {
            dp[u] = std::max(dp[u], dp[v] + 1);
        }
    }

    std::cout << (dp[uf.find(N - 1)] == -INF ? 0 : dp[uf.find(N - 1)]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
