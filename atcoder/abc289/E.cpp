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

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    queue<pair<int, int>> q;
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    
    if(A[0] == A[N - 1]) {
        cout << -1 << '\n';
        return;
    }

    q.emplace(0, N - 1);
    vis[0][N - 1] = true;
    int d = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            pair<int, int> cur = q.front();
            q.pop();

            int u = cur.first;
            int v = cur.second;
            if(u == N - 1 && v == 0) {
                cout << d << '\n';
                return;
            }

            for(int nu : G[u]) {
                for(int nv : G[v]) {
                    if(A[nu] != A[nv] && !vis[nu][nv]) {
                        vis[nu][nv] = true;
                        q.emplace(nu, nv);
                    } 
                }
            }
        }
        d += 1;
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
