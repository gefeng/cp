#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

bool dfs(vector<vector<int>>& G, int ed, vector<bool>& visited, int cur, vector<int>& path) {
    visited[cur] = true;
    path.push_back(cur);

    if(cur == ed) {
        return true;
    }

    for(int nei : G[cur]) {
        if(!visited[nei]) {
            if(dfs(G, ed, visited, nei, path)) {
                return true;
            }
        }
    }

    path.pop_back();
    return false;
}

void run_case() {
    int N, X, Y;
    cin >> N >> X >> Y;

    X--;
    Y--;

    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        cin >> U >> V;

        U--;
        V--;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    vector<bool> visited(N, false);
    vector<int> path;
    dfs(G, Y, visited, X, path);

    int n = path.size();
    for(int i = 0; i < n; i++) {
        cout << path[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
