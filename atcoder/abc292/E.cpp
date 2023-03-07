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

    auto bfs = [&](int s) -> int {
        queue<int> q;
        vector<int> dist(N, INF);

        q.push(s);
        dist[s] = 0;

        int d = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int v = q.front();
                q.pop();
                for(int nei : G[v]) {
                    if(dist[nei] == INF) {
                        dist[nei] = d + 1;
                        q.push(nei);
                    }
                }
            }
            d += 1;
        }

        int res = 0;
        for(int i = 0; i < N; i++) {
            if(dist[i] != INF && dist[i] > 1) {
                res += 1;
            }
        }
        return res;
    };

    int ans = 0;
    for(int i = 0; i < N; i++) {
        ans += bfs(i);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
