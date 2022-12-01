#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

struct dsu {
    int n;
    vector<int> p;
    vector<int> w;
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
            w[y] = w[x];
        }
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }
};

void run_case() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<array<int, 4>> E(M + Q);
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> E[i][j];
        }
        E[i][3] = -1;
        E[i][0] -= 1;
        E[i][1] -= 1;
    }

    for(int i = M; i < Q + M; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> E[i][j];
        }
        E[i][3] = i - M;
        E[i][0] -= 1;
        E[i][1] -= 1;
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a[2] < b[2];
    };

    sort(E.begin(), E.end(), cmp);

    dsu uf(N);
    vector<bool> ans(Q, false);
    for(auto& e : E) {
        int u = e[0];
        int v = e[1];
        if(uf.same(u, v)) {
            if(e[3] != -1) {
                ans[e[3]] = false;
            }
        } else {
            if(e[3] != -1) {
                ans[e[3]] = true;
            } else {
                uf.unite(u, v);
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        cout << (ans[i] ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
