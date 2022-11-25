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

    int size(int i) {
        return w[find(i)];
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
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    LL sum = 0LL;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }

    dsu uf(N);
    bool ok = true;
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        
        if(uf.same(U, V)) {
            ok = false;
        }
        uf.unite(U, V);
        
        A[U] -= 1;
        A[V] -= 1;
    }

    if(!ok) {
        cout << -1 << '\n';
        return;
    }

    for(int d : A) {
        if(d < 0) {
            cout << -1 << '\n';
            return;
        }
    }

    // degree sum of a tree is 2 * (N - 1)
    if(sum != 2 * N - 2) { 
        cout << -1 << '\n';
        return;
    }

    vector<vector<int>> comp(N);
    for(int i = 0; i < N; i++) {
        int p = uf.find(i);
        for(int j = 0; j < A[i]; j++) {
            comp[p].push_back(i);
        }
    } 

    set<pair<int, int>> g_d;
    for(int i = 0; i < N; i++) {
        int p = uf.find(i);
        if(p == i) {
            if(comp[p].empty()) {
                cout << -1 << '\n';
                return;
            }
            g_d.emplace(comp[p].size(), p);
        }
    }
   
    while(g_d.size() > 1) {
        auto it_1 = g_d.begin();
        auto it_2 = g_d.end();
        it_2--;

        int p_1 = it_1->second;
        int p_2 = it_2->second;
    
        cout << comp[p_1].back() + 1 << ' ' << comp[p_2].back() + 1 << '\n';
        
        comp[p_1].pop_back();
        comp[p_2].pop_back();

        for(int x : comp[p_1]) {
            comp[p_2].push_back(x);
        }

        g_d.erase(it_1);
        g_d.erase(it_2);
        g_d.emplace(comp[p_2].size(), p_2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
