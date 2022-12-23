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
    
    int size(int i) {
        return w[find(i)];
    }
};

void run_case() {
    int N;
    cin >> N;

    vector<pair<int, pair<int, int>>> E;

    for(int i = 0; i < N - 1; i++) {
        int U, V, W;
        cin >> U >> V >> W;

        U -= 1;
        V -= 1;

        E.emplace_back(W, pair<int, int>(U, V));
    }

    sort(E.begin(), E.end()); 

    dsu uf(N);
    LL ans = 0LL;
    for(auto& e : E) {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;

        int sz1 = uf.size(u);
        int sz2 = uf.size(v);
        ans += 1LL * w * sz1 * sz2;
        
        uf.unite(u, v);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
