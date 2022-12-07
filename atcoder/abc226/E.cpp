#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = 998244353LL;

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
    int size(int i) {
        return w[find(i)];
    }
    int count() {
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(p[i] < 0) {
                res += 1;
            }
        }
        return res;
    }
};

void run_case() {
    int N, M;
    cin >> N >> M;

    dsu uf(N);
    vector<pair<int, int>> E(M);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        uf.unite(U, V);
        E[i] = {U, V};
    }

    vector<int> cnt_e(N, 0);
    for(auto& e : E) {
        cnt_e[uf.find(e.first)] += 1;
    }

    LL ans = 1LL;
    for(int i = 0; i < N; i++) {
        if(uf.find(i) == i) {
            if(cnt_e[i] == uf.size(i)) {
                ans *= 2LL;
                ans %= MOD;
            } else {
                cout << 0 << '\n';
                return;
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
