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
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;

        U -= 1;
        V -= 1;

        G[U].push_back(V);
        G[V].push_back(U);
    }

    queue<int> q;
    vector<bool> vis(N, false);
    vector<int> pre(N, -1);

    q.push(0);
    vis[0] = true;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int v = q.front();
            q.pop();

            for(int nei : G[v]) {
                if(!vis[nei]) {
                    vis[nei] = true;
                    q.push(nei);
                    pre[nei] = v;
                }
            }
        }
    }

    for(int i = 1; i < N; i++) {
        if(pre[i] == -1) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
    for(int i = 1; i < N; i++) {
        cout << pre[i] + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
