#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void get_depth(vector<vector<int>>& G, vector<int>& depth, int v, int p, int cur_depth) {
    depth[v] = cur_depth;
    
    for(int u : G[v]) {
        if(u != p) {
            get_depth(G, depth, u, v, cur_depth + 1);
        }
    }
}

void dfs(vector<vector<int>>& G, vector<LL>& delta, vector<LL>& ans, int v, int p, LL sum) {
    sum += delta[v];
    ans[v] = sum;

    for(int u : G[v]) {
        if(u != p) {
            dfs(G, delta, ans, u, v, sum);
        }
    }
}

void run_case() {
    int N;
    cin >> N;

    vector<pair<int, int>> E(N - 1);
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        cin >> E[i].first >> E[i].second;
        E[i].first -= 1;
        E[i].second -= 1;

        G[E[i].first].push_back(E[i].second);
        G[E[i].second].push_back(E[i].first);
    }

    vector<int> depth(N, 0);
    get_depth(G, depth, 0, -1, 0);

    vector<LL> delta(N, 0LL);
    int Q;
    cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T, I, X;
        cin >> T >> I >> X;

        int u = E[I - 1].first;
        int v = E[I - 1].second;

        int du = depth[u];
        int dv = depth[v];

        if(T == 1) {
            if(du < dv) {
                delta[0] += X;
                delta[v] -= X;
            } else {
                delta[u] += X;
            }
        } else {
            if(du < dv) {
                delta[v] += X;
            } else {
                delta[0] += X;
                delta[u] -= X;
            }
        }
    }

    vector<LL> ans(N, 0LL);
    dfs(G, delta, ans, 0, -1, 0LL);

    for(int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
