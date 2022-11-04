#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;
using LL = long long;

LL bfs(vector<vector<int>>& G, int s, int d) {
    queue<int> q;
    unordered_set<int> vis;

    q.push(s);
    vis.insert(s);

    LL ans = 0LL;
    while(!q.empty() && d >= 0) {
        int sz = q.size();
        while(sz--) {
            int cur = q.front();
            q.pop();

            ans += cur + 1;

            for(int nei : G[cur]) {
                if(vis.find(nei) == vis.end()) {
                    vis.insert(nei);
                    q.push(nei);
                }
            }
        }
        d -= 1;
    } 

    return ans;
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

    int Q;
    cin >> Q;

    for(int i = 0; i < Q; i++) {
        int X, D;
        cin >> X >> D;
        X -= 1;

        cout << bfs(G, X, D) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
