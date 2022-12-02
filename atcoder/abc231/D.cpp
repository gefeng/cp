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
            w[y] += w[x];
        }
    }
};

void run_case() {
    int N, M;
    cin >> N >> M;

    dsu uf(N);
    vector<int> deg(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        uf.unite(U, V);
        deg[U] += 1;
        deg[V] += 1;
    }

    vector<vector<int>> g(N);
    for(int i = 0; i < N; i++) {
        int p = uf.find(i);
        g[p].push_back(i);
    }

    for(int i = 0; i < N; i++) {
        if(g[i].size()) {
            if(g[i].size() == 1) {
                continue;
            }
            int cnt = 0;
            for(int x : g[i]) {
                if(deg[x] > 2) {
                    cout << "No" << '\n';
                    return;
                }
                if(deg[x] & 1) {
                    cnt += 1;
                }
            } 
            if(cnt != 2) {
                cout << "No" << '\n';
                return;
            }
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
