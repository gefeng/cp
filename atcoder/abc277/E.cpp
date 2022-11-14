#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INF = (int)2e9;

void run_case() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<int, int>>> G(N << 1);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        U--;
        V--;

        if(W) {
            G[U].emplace_back(V, 1); 
            G[V].emplace_back(U, 1);
        } else {
            G[U + N].emplace_back(V + N, 1);
            G[V + N].emplace_back(U + N, 1);
        }
    }

    for(int i = 0; i < K; i++) {
        int V;
        cin >> V;
        V--;
        G[V].emplace_back(V + N, 0);
        G[V + N].emplace_back(V, 0);
    }
    
    deque<pair<int, int>> q;
    vector<int> dist(N * 2, INF);

    q.emplace_back(0, 0);
    dist[0] = 0; 

    while(q.size()) {
        pair<int, int> cur = q.front();
        q.pop_front();

        int v = cur.first;
        int d = cur.second;

        if(d != dist[v]) {
            continue;
        }

        for(auto& nei : G[v]) {
            int nv = nei.first;
            int nd = d + nei.second;

            if(nd < dist[nv]) {
                dist[nv] = nd;
                if(nd == d) {
                    q.emplace_front(nv, nd);
                } else {
                    q.emplace_back(nv, nd);
                }
            }
        }
    }

    int ans = min(dist[N - 1], dist[N + N - 1]);

    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
