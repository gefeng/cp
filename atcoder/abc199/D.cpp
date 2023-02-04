#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void dfs1(vector<vector<int>>& G, vector<bool>& vis, vector<int>& component, int v) {
    component.push_back(v);
    
    vis[v] = true;

    for(int nei : G[v]) {
        if(!vis[nei]) {
            dfs1(G, vis, component, nei);
        }
    }
}

LL dfs2(vector<vector<int>>& G, vector<int>& color, vector<int>& component, int i) {
    if(i == component.size()) {
        return 1LL;
    }

    LL res = 0LL;
    for(int c = 0; c < 3; c++) {
        bool ok = true;
        for(int nei : G[component[i]]) {
            if(color[nei] == c) {
                ok = false;
                break;
            } 
        }

        if(ok) {
            color[component[i]] = c;
            res += dfs2(G, color, component, i + 1);
            color[component[i]] = -1;
        }
    }
    
    return res;
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

    LL ans = 1LL;
    vector<bool> vis(N, false);
    vector<int> color(N, -1);
    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            vector<int> component;
            dfs1(G, vis, component, i);

            ans *= dfs2(G, color, component, 0); 
        } 
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
