#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int bfs_1(vector<vector<pair<int, int>>>& G, int N, int M, vector<bool>& on_path) {
    queue<pair<int, int>> q;
    vector<bool> vis(N, false);
    vector<int> pre_e(M, -1);
    
    q.emplace(0, -1);
    vis[0] = true;

    int d = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            pair<int, int> cur = q.front();
            q.pop();

            int v = cur.first;
            int e = cur.second;

            if(v == N - 1) {
                int cur = e;
                while(cur != -1) {
                    on_path[cur] = true;
                    cur = pre_e[cur];
                }
                return d;  
            }

            for(auto& nei : G[v]) {
                int nv = nei.first;
                int ne = nei.second;

                if(!vis[nv]) {
                    vis[nv] = true;
                    pre_e[ne] = e;
                    q.emplace(nv, ne);
                }
            }
        }
        d += 1;
    }

    return -1;
}

int bfs_2(vector<vector<pair<int, int>>>& G, int N, int M, int e_i) {
    queue<int> q;
    vector<bool> vis(N, false);
    
    q.push(0);
    vis[0] = true;
    
    int d = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int cur = q.front();
            q.pop();

            if(cur == N - 1) {
                return d;
            }

            for(auto& nei : G[cur]) {
                if(nei.second != e_i && !vis[nei.first]) {
                    q.push(nei.first);
                    vis[nei.first] = true;
                }
            }
        }
        d += 1;
    }

    return -1;
}

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;

        U -= 1;
        V -= 1;

        G[U].emplace_back(V, i);
    }

    vector<bool> on_path(M, false);
    int best = bfs_1(G, N, M, on_path);
    
    for(int i = 0; i < M; i++) {
        if(on_path[i]) {
            cout << bfs_2(G, N, M, i) << '\n';
        } else {
            cout << best << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
