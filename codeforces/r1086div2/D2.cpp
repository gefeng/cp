#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

struct dsu {
    int n;
    std::vector<int> p;
    std::vector<int> w;

    dsu(int n_) : n(n_), p(n_, -1), w(n_, 1) {}

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
    int N;
    std::cin >> N;

    std::vector<std::string> A(N);
    std::vector<std::vector<int>> G(N);
    std::vector<int> ind(N, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        for(int j = 0; j < N; j++) {
            if(i != j && A[i][j] == '1') {
                G[i].push_back(j);
                ind[j]++;
            }
        }
    }

    auto has_cycle = [&]() {
        std::queue<int> q;
        for(int v = 0; v < N; v++) {
            if(ind[v] == 0) {
                q.push(v); 
            }
        }

        int solved = 0;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            
            solved++;
            
            for(int u : G[v]) {
                if(--ind[u] == 0) {
                    q.push(u);
                }
            }
        }

        return solved < N;
    };

    if(has_cycle()) {
        std::cout << "No" << '\n';
        return;
    }

    std::vector<std::vector<int>> adj(N, std::vector<int>(N, 0));
    std::vector<int> cnt_reachable(N, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j && A[i][j] == '0') {
                std::cout << "No" << '\n';
                return;
            }

            cnt_reachable[i] += A[i][j] - '0';
        }
    }

    std::vector<std::vector<int>> a(N + 1);
    std::vector<int> removed(N, 0);
    for(int i = 0; i < N; i++) {
        std::vector<int> sorted;
        for(int j = 0; j < N; j++) {
            if(i != j && A[i][j] == '1') {
                a[cnt_reachable[j]].push_back(j);
            }
        }
        
        for(int j = N; j > 0; j--) {
            for(int v : a[j]) {
                sorted.push_back(v);
            }
        }

        for(int v : sorted) {
            if(removed[v]) {
                continue;
            }
            adj[i][v] = 1;
            for(int u : G[v]) {
                removed[u] = 1;
            }
            removed[v] = 1; 
        }
        
        for(int j = 0; j <= N; j++) {
            a[j].clear();
        }
        for(int j = 0; j < N; j++) {
            removed[j] = 0;
        }
    }

    auto check = [&](std::vector<std::vector<int>>& edges) {
        std::vector<std::vector<int>> g(N);
        dsu uf(N);
        int cnt_e = 0;
        for(int v = 0; v < N; v++) {
            for(int u = 0; u < N; u++) {
                if(edges[v][u]) {
                    cnt_e++;
                    g[v].push_back(u);
                    if(uf.same(u, v)) {
                        return false;
                    }
                    uf.unite(u, v);
                }
            }
        }
        if(cnt_e != N - 1) {
            return false;
        }

        for(int v = 0; v < N; v++) {
            std::string s(N, '0');
            s[v] = '1';
            std::queue<int> q;
            q.push(v);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int nei : g[u]) {
                    if(s[nei] == '0') {
                        q.push(nei);
                        s[nei] = '1';
                    }
                }
            }
            if(s != A[v]) {
                return false;
            }
        }
        return true;
    };

    std::vector<std::pair<int, int>> ans;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(adj[i][j]) {
                ans.emplace_back(i, j);
            }
        }
    }
    if(!check(adj) || ans.size() != N - 1) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
    for(auto [u, v] : ans) {
        std::cout << u + 1 << ' ' << v + 1 << '\n';
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
