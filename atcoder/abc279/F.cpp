#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

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
};

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<int> box(N + 1);
    map<int, int> m;
    for(int i = 1; i <= N; i++) {
        box[i] = i;
        m[i] = i;
    }

    dsu uf(N + Q + 5);
    int k = N + 1;
    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        if(T == 1) {
            int X, Y;
            cin >> X >> Y;
            
            int p_1 = box[X];
            int p_2 = box[Y];

            if(p_2 == -1) {
                continue;
            }

            if(p_1 == -1) {
                box[X] = p_2;
                box[Y] = -1;
                m[p_2] = X;
            } else {
                uf.unite(p_1, p_2);
                int p = uf.find(p_1);
                box[X] = p;
                box[Y] = -1;
                
                m.erase(p_2);
                m.erase(p_1);
                m[p] = X;
            }
        } else if(T == 2) {
            int X;
            cin >> X;

            int p = box[X];
            if(p != -1) {
                uf.unite(k, p);
                m.erase(p);
            }
            p = uf.find(k);
            box[X] = p;
            m[p] = X;

            k += 1;
        } else {
            int X;
            cin >> X;

            cout << m[uf.find(X)] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
