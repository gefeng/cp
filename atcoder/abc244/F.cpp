#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using LL = long long;

const int INF = (int)2e9;

void bfs(vector<vector<int>>& G, int st, vector<int>& res) {
    int n = G.size();

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(1 << n, false));

    q.emplace(st, 1 << st);
    vis[st][1 << st] = true;

    int len = 1;
    while(!q.empty()) {
        int sz = q.size();

        while(sz--) {
            pair<int, int> cur = q.front();
            q.pop();

            int v = cur.first;
            int m = cur.second;
            
            res[m] = min(res[m], len);
            
            for(int nei : G[v]) {
                int n_m = m ^ (1 << nei);
                if(!vis[nei][n_m]) {
                    q.emplace(nei, n_m);
                    vis[nei][n_m] = true;
                }
            }
        }
        len += 1;
    }
}

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    vector<int> res(1 << N, INF);
    res[0] = 0;
    for(int i = 0; i < N; i++) {
        bfs(G, i, res);
    }

    LL ans = 0LL;
    for(int x : res) {
        ans += x;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
