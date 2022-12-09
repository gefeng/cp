#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;
 
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
    bool same(int i, int j) {
        return find(i) == find(j);
    }
};
 
void run_case() {
    int N, M;
    cin >> N >> M;
 
    vector<array<int, 3>> E(M);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> E[i][j];
        }
        E[i][0] -= 1;
        E[i][1] -= 1;
    }
 
    auto cmp = [](const auto& a, const auto& b) {
        return a[2] < b[2];
    };
 
    sort(E.begin(), E.end(), cmp);
 
    dsu uf(N);
    LL ans = 0LL;
    for(auto& e : E) {
        if(e[2] < 0) {
            uf.unite(e[0], e[1]);
        } else {
            if(uf.same(e[0], e[1])) {
                ans += e[2];
            } else {
                uf.unite(e[0], e[1]);
            }
        }
    }
 
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
