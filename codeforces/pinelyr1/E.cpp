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
 
    int count() {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(p[i] < 0) {
                cnt += 1;
            }
        }
        return cnt;
    }
 
    vector<vector<int>> groups() {
        int tot = count();
        vector<vector<int>> g;
        g.reserve(tot);
 
        for(int i = 0; i < n; i++) {
            if(p[i] < 0) {
                g.emplace_back();
                for(int j = 0; j < n; j++) {
                    if(find(j) == i) {
                        g.back().push_back(j); 
                    }
                }
            }
        }
 
        return g;
    }
};
 
void run_case() {
    int N;
    cin >> N;
 
    vector<string> G(N);
    for(int i = 0; i < N; i++) {
        cin >> G[i];
    }
 
    dsu uf(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(G[i][j] == '1') {
                uf.unite(i, j);
            }
        }
    }
 
    if(uf.count() == 1) {
        cout << 0 << '\n';
        return;
    }
 
    int ans = N;
    vector<int> seq;
    for(auto& g : uf.groups()) {
        int sz = g.size();
        if(sz == 1) {
            cout << 1 << '\n';
            cout << g[0] + 1 << '\n';
            return;
        }
 
        int min_cnt = sz;
        int min_v = 0;
        for(int v : g) {
            int cnt = 0;
            for(int u : g) {
                if(G[u][v] == '1') {
                    cnt += 1;
                }
            }
            if(sz > 2 && cnt == 1) {
                cout << 1 << '\n';
                cout << v + 1 << '\n';
                return;
            }
            
            if(cnt < min_cnt) {
                min_cnt = cnt;
                min_v = v;
            }
        }
 
        if(min_cnt < sz - 1) {
            cout << 1 << '\n';
            cout << min_v + 1 << '\n';
            return;
        }
 
        if(sz < ans) {
            ans = sz;
            seq = vector<int>();
            for(int v : g) {
                seq.push_back(v + 1);
            }
        }
    }
 
    if(uf.count() > 2) {
        cout << 2 << '\n';
        vector<vector<int>> gs = uf.groups();
        cout << gs[0][0] + 1 << ' ' << gs[1][0] + 1 << '\n';
        return;
    }
 
    cout << ans << '\n';
    for(int i = 0; i < ans; i++) {
        cout << seq[i] << " \n"[i == ans - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
