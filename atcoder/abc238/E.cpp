#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

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

    bool same(int i, int j) {
        return find(i) == find(j);
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

    int count() {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(p[i] < 0) {
                cnt += 1;
            }
        }
        return cnt;
    }
};

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<pair<int, int>> A(Q);
    for(int i = 0; i < Q; i++) {
        cin >> A[i].first >> A[i].second;
    }

    dsu uf(N + 1);
    for(auto& p : A) {
        uf.unite(p.first - 1, p.second);
    }

    cout << (uf.same(0, N) ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
