#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const int MAX = (int)1e5;
const LL MOD = 998244353LL;

bool dfs(vector<vector<pair<int, int>>>& G, vector<int>& cnt_e, int t, int v, int p) {
    if(v == t) {
        return true;
    }

    for(auto& nei : G[v]) {
        if(nei.first != p) {
            if(dfs(G, cnt_e, t, nei.first, v)) {
                cnt_e[nei.second] += 1;
                return true;
            }
        } 
    }

    return false;
}

void run_case() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;

        G[U].emplace_back(V, i);
        G[V].emplace_back(U, i);
    }

    vector<int> cnt_e(N - 1, 0);
    for(int i = 0; i < M - 1; i++) {
        dfs(G, cnt_e, A[i + 1], A[i], -1);
    }

    vector<int> v;
    for(int i = 0; i < N - 1; i++) {
        if(cnt_e[i]) {
            v.push_back(cnt_e[i]);
        }
    }
    
    int n = v.size();
    vector<LL> dp(MAX * 2 + 1, 0LL);
    dp[MAX] = 1LL;

    for(int i = 1; i <= n; i++) {
        vector<LL> ndp(MAX * 2 + 1, 0LL);
        
        for(int j = -MAX; j <= MAX; j++) {
            if(j - v[i - 1] + MAX >= 0) {
                ndp[j + MAX] += dp[j - v[i - 1] + MAX];
                ndp[j + MAX] %= MOD;
            }
            if(j + v[i - 1] + MAX <= MAX * 2) {
                ndp[j + MAX] += dp[j + v[i - 1] + MAX];
                ndp[j + MAX] %= MOD;
            }
        }

        swap(dp, ndp);
    }

    LL ans = dp[K + MAX];
    for(int i = 0; i < N - 1; i++) {
        if(cnt_e[i] == 0) {
            ans *= 2LL;
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
