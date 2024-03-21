#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>

struct dsu {
    int n;
    std::vector<int> p;
    std::vector<int> w;
    dsu(int n) : n(n), p(n, -1), w(n, 1) {}
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

void dfs(std::vector<std::vector<int>>& G, std::map<std::pair<int, int>, int>& E, std::vector<int>& vis, 
        std::vector<int>& on, int& K, int v, int p, std::vector<int>& ans) {
    vis[v] = 1;
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, E, vis, on, K, nei, v, ans);
        }
    }

    if(!on[v] && p != -1 && K) {
        ans.push_back(E[{v, p}]);
        K -= 1;
        K += on[p] ? 1 : -1;
        on[v] ^= 1;
        on[p] ^= 1;
    }
}

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::map<std::pair<int, int>, int> E;
    std::vector<std::vector<int>> G(N);
    dsu uf(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        if(uf.same(U, V)) {
            continue;
        }

        uf.unite(U, V);
        E[{U, V}] = i;
        E[{V, U}] = i;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    if(K % 2 == 1) {
        std::cout << "No" << '\n';
        return;
    }

    std::vector<int> ans;
    std::vector<int> on(N, 0);
    std::vector<int> vis(N, 0);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }
        dfs(G, E, vis, on, K, i, -1, ans);
    }


    if(K) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
    int n = ans.size();
    std::cout << n << '\n';
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
