#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = (LL)1e18;

struct dsu {
public:
    dsu(int n) : _n(n) {
        _p.resize(n, -1);
        _w.resize(n, 1);
    }

    int find(int i) {
        if(_p[i] < 0) {
            return i;
        }
        return _p[i] = find(_p[i]);
    }

    bool same(int i, int j) {
        return find(i) == find(j);
    }

    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) {
            return;
        }

        if(_w[x] >= _w[y]) {
            _p[y] = x;
            _w[x] += _w[y];
        } else {
            _p[x] = y;
            _w[y] += _w[x];
        }
    }

    int size(int i) {
        return _w[find(i)];
    }
    
private:
    int _n;
    vector<int> _p;
    vector<int> _w;
};

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> X(N, 0);
    vector<int> Y(N, 0);
    vector<array<int, 3>> Z(M, {0});

    for(int i = 0; i < N; i++) {
        cin >> X[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> Y[i];
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> Z[i][j];
        }
        for(int j = 0; j < 2; j++) {
            Z[i][j]--;
        }
    }
    
    auto cmp = [](auto& a, auto& b) {
        return a[2] < b[2];
    }; 

    LL ans = INF;
    for(int i = 0; i < 4; i++) {
        vector<array<int, 3>> E;
        E.reserve(M + 2 * N);

        int tot = N;

        for(int j = 0; j < M; j++) {
            E.push_back(Z[j]);
        }

        if(i & 1) {
            for(int j = 0; j < N; j++) {
                E.push_back({j, N, X[j]});
            }
            tot++;
        }
        if(i & 2) {
            for(int j = 0; j < N; j++) {
                E.push_back({j, N + 1, Y[j]});
            }
            tot++;
        }

        sort(E.begin(), E.end(), cmp);

        dsu uf(N + 2);
        LL cost = 0LL;
        for(auto& e : E) {
            int x = e[0];
            int y = e[1];
            int w = e[2];

            if(!uf.same(x, y)) {
                uf.unite(x, y);
                cost += w;
            }
        }

        if(uf.size(0) == tot) {
            ans = min(ans, cost);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
