#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

bool dfs(vector<vector<int>>& G, vector<int>& color, vector<int>& nodes, int v, int c) {
    if(color[v] != -1) {
        return color[v] == c;
    }

    nodes.push_back(v);
    color[v] = c;

    for(int nei : G[v]) {
        if(!dfs(G, color, nodes, nei, c ^ 1)) {
            return false;
        }
    }

    return true;
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
    
    LL ans = 0LL;
    vector<int> color(N, -1);
    vector<int> groups;
    for(int i = 0; i < N; i++) {
        vector<int> nodes;
        if(color[i] == -1) {
            if(!dfs(G, color, nodes, i, 0)) {
                cout << 0 << '\n';
                return;
            }
        }

        int cnt = 0;
        for(int v : nodes) {
            if(color[v] == 1) {
                cnt += 1;
            }
        }
        for(int v : nodes) {
            int e = G[v].size();
            if(color[v] == 0) {
                ans += cnt - e;
            }
        }

        groups.push_back(nodes.size());
    }

    int cur = N;
    for(int g : groups) {
        cur -= g;
        ans += 1LL * g * cur;
    }

    cout << ans << '\n'; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
