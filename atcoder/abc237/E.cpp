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

const LL INF = 2e18;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        cin >> U >> V;
        U -= 1;
        V -= 1;

        G[U].emplace_back(V, A[U] >= A[V] ? 0 : A[V] - A[U]);
        G[V].emplace_back(U, A[V] >= A[U] ? 0 : A[U] - A[V]);
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a.second > b.second;
    };

    priority_queue<pair<int, LL>, vector<pair<int, LL>>, decltype(cmp)> pq(cmp);
    vector<LL> dist(N, INF);

    pq.emplace(0, 0LL);
    dist[0] = 0LL;

    while(!pq.empty()) {
        pair<int, LL> cur = pq.top();
        pq.pop();

        int v = cur.first;
        LL d = cur.second;

        if(d != dist[v]) {
            continue;
        }

        for(pair<int, int>& nei : G[v]) {
            int nv = nei.first;
            LL nd = d + nei.second;
            if(nd < dist[nv]) {
                dist[nv] = nd;
                pq.emplace(nv, nd);
            }
        }
    }

    LL ans = INF;
    for(int i = 0; i < N; i++) {
        ans = min(ans, dist[i] - A[0] + A[i]);
    }

    cout << ans * -1LL << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
