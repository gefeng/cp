#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<vector<array<int, 3>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        U -= 1;
        V -= 1;

        G[U].push_back({V, W, i + 1});
        G[V].push_back({U, W, i + 1});
    }

    auto cmp = [](array<LL, 3>& a, array<LL, 3>& b) {
        return a[1] > b[1];
    };

    priority_queue<array<LL, 3>, vector<array<LL, 3>>, decltype(cmp)> pq(cmp);
    vector<LL> dist(N, INF);
    vector<int> ans(N, -1);

    pq.push({0LL, 0LL, -1LL});
    dist[0] = 0LL;
    while(!pq.empty()) {
        array<LL, 3> cur = pq.top();
        pq.pop();
        
        if(cur[1] != dist[cur[0]]) {
            continue;
        }

        for(array<int, 3>& nei : G[(int)cur[0]]) {
            LL d = cur[1] + nei[1];
            if(dist[nei[0]] > d) {
                dist[nei[0]] = d;
                ans[nei[0]] = nei[2];
                pq.push({(LL)nei[0], d, (LL)nei[2]});
            }
        }
    }

    for(int i = 1; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
