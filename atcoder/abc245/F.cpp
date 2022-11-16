#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(N);
    vector<int> deg(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;

        G[V].push_back(U);
        deg[U] += 1;
    }

    queue<int> q;
    for(int i = 0; i < N; i++) {
        if(deg[i] == 0) {
            q.push(i);
        }
    }

    int ans = N;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        ans -= 1;
        
        for(int u : G[v]) {
            if(--deg[u] == 0) {
                q.push(u);
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
