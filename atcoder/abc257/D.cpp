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

void dfs(vector<vector<int>>& g, vector<bool>& vis, int cur) {
    vis[cur] = true;
    for(int nei : g[cur]) {
        if(!vis[nei]) {
            dfs(g, vis, nei);
        }
    }
}
void run_case() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N), P(N);
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> P[i];
    }

    vector<vector<LL>> w(N, vector<LL>(N));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            w[i][j] = (1LL * abs(X[i] - X[j]) + abs(Y[i] - Y[j]) + P[i] - 1LL) / P[i];
        }
    }

    LL ans = (LL)4e9;
    for(int s = 0; s < N; s++) {
        LL max_w = 0LL;

        vector<LL> d(N, INF);
        vector<bool> vis(N, false);
        
        d[s] = 0LL;

        for(int i = 0; i < N; i++) {
            int x = -1;
            for(int j = 0; j < N; j++) {
                if(!vis[j] && (x == -1 || d[j] < d[x])) {
                    x = j;
                }
            }

            vis[x] = true;
            max_w = max(max_w, d[x]);
            for(int j = 0; j < N; j++) {
                d[j] = min(d[j], w[x][j]);
            }
        }

        ans = min(ans, max_w);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
