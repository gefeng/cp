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
        if(p[i] < 0) return i;
        return p[i] = find(p[i]);
    }
    void unite(int i, int j) {
        int x = find(i);
        int y = find(j);
        if(x == y) return;

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
    vector<int> groups() {
        vector<int> g;
        for(int i = 0; i < n; i++) {
            if(p[i] < 0) {
                g.push_back(size(i));
            }
        }
        return g;
    }
};

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
        B[i] -= 1;
    }

    dsu uf(N);
    for(int i = 0; i < N; i++) {
        uf.unite(A[i], B[i]);
    }

    vector<vector<vector<LL>>> dp(N + 1, vector<vector<LL>>(2, vector<LL>(2, 0LL)));
    dp[1][0][0] = 1LL;
    dp[1][1][1] = 1LL;
    
    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < 2; j++) {
            dp[i][j][0] = dp[i - 1][j][1];
            dp[i][j][1] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
        }
    }

    LL ans = 1LL;
    for(int x : uf.groups()) {
        ans *= (dp[x][0][1] + dp[x][1][0] + dp[x][1][1]) % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
