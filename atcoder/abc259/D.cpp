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
    int N; 
    cin >> N;

    LL S_X, S_Y, T_X, T_Y;
    cin >> S_X >> S_Y >> T_X >> T_Y;

    vector<array<LL, 3>> A(N, {0LL});

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    int s_on_which = -1;
    int t_on_which = -1;
    for(int i = 0; i < N; i++) {
        LL x = A[i][0] - S_X;
        LL y = A[i][1] - S_Y;
        if(x * x + y * y == A[i][2] * A[i][2]) {
            s_on_which = i;
        }

        x = A[i][0] - T_X;
        y = A[i][1] - T_Y;
        if(x * x + y * y == A[i][2] * A[i][2]) {
            t_on_which = i;
        }
    }

    if(s_on_which == -1 || t_on_which == -1) {
        cout << "No" << '\n';
        return;
    }

    dsu uf(N);
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            LL x = A[i][0] - A[j][0];
            LL y = A[i][1] - A[j][1];
            LL r_1 = A[i][2] + A[j][2];
            LL r_2 = abs(A[i][2] - A[j][2]); 
            if(x * x + y * y <= r_1 * r_1 && x * x + y * y >= r_2 * r_2) {
                uf.unite(i, j);
            }
        }
    }

    cout << (uf.same(s_on_which, t_on_which) ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
