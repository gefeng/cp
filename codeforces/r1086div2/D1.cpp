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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    std::vector<std::vector<int>> RG(N);
    std::vector<int> ind(N, 0);
    std::vector<int> outd(N, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j] == '1' && i != j) {
                G[i].push_back(j);
                RG[j].push_back(i);
                ind[j]++;
                outd[i]++;
            }
            if(i == j && A[i][j] != '1') {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    // O(N)
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

    // O(N) ? 
    auto build = [&](int s) {
        std::vector<int> pre(N, -1);
        std::vector<int> dist(N, 0);
        std::queue<int> q;

        q.push(s);
        while(!q.empty()) {
            int v = q.front();
            q.pop();

            for(int u : RG[v]) {
                if(dist[v] + 1 > dist[u]) {
                    dist[u] = dist[v] + 1;
                    pre[u] = v;
                    q.push(u);
                }
            }
        }

        return pre;
    };

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
            std::vector<int> vis(N, 0);
            s[v] = '1';
            vis[v] = 1;
            std::queue<int> q;
            q.push(v);
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int nei : g[u]) {
                    if(!vis[nei]) {
                        vis[nei] = 1;
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

    if(has_cycle()) {
        std::cout << "No" << '\n';
        return;
    }

    std::vector<std::vector<int>> ans(N, std::vector<int>(N, 0));
    for(int v = 0; v < N; v++) {
        if(outd[v]) {
            continue;
        }

        std::vector<int> pre = build(v);
        for(int u = 0; u < N; u++) {
            if(pre[u] != -1) {
                ans[u][pre[u]] = 1;
            }
        }
    }

    if(!check(ans)) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
    for(int v = 0; v < N; v++) {
        for(int u = 0; u < N; u++) {
            if(ans[v][u]) {
                std::cout << v + 1 << ' ' << u + 1 << '\n';
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
