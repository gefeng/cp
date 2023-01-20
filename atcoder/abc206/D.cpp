#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

const int MAX = (int)2e5;

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
};

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    dsu uf(MAX + 1);

    for(int i = 0; i < N / 2; i++) {
        if(A[i] != A[N - i - 1]) {
            uf.unite(A[i], A[N - i - 1]); 
        }
    }

    set<int> s;
    for(int i = 0; i < N; i++) {
        s.insert(uf.find(A[i]));
    }
    
    int ans = 0;
    for(int p : s) {
        ans += uf.size(p) - 1;
    } 
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
