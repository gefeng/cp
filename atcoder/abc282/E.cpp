#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

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

LL q_pow(LL x, LL y, LL MOD) {
    LL res = 1LL;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1LL;
    }
    return res;
}

void run_case() {
    int N;
    LL M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> edges;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int w = (q_pow(A[i], A[j], M) + q_pow(A[j], A[i], M)) % M;
            edges.emplace_back();

            edges.back().push_back(i);
            edges.back().push_back(j);
            edges.back().push_back(w);
        }
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a[2] > b[2];
    };

    sort(edges.begin(), edges.end(), cmp);

    dsu uf(N);
    LL ans = 0LL;
    for(auto& e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
       
        if(uf.same(u, v)) {
            continue;
        }

        uf.unite(u, v);
        ans += w;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
