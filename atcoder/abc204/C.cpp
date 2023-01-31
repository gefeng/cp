#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& G, vector<bool>& vis, int v) {
    vis[v] = true;
    for(int nei : G[v]) {
        if(!vis[nei]) {
            dfs(G, vis, nei);
        }
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
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        vector<bool> vis(N, false);
        dfs(G, vis, i);
        for(int j = 0; j < N; j++) {
            if(vis[j]) {
                ans += 1;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
