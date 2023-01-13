#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int MAX = (int)1e6;

int cnt = 0;

void dfs(vector<vector<int>>& G, vector<bool>& vis, int v) {
    if(cnt >= MAX) {
        return;
    }

    //cout << v << '\n';

    vis[v] = true;
    cnt += 1;

    for(int nei : G[v]) {
        if(!vis[nei]) {
            dfs(G, vis, nei);
        }
    }

    vis[v] = false;
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

    vector<bool> vis(N, false);

    dfs(G, vis, 0);

    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
