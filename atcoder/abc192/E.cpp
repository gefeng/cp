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
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    X -= 1;
    Y -= 1;

    vector<vector<tuple<int, int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int A, B, T, K;
        cin >> A >> B >> T >> K;
        A -= 1;
        B -= 1;
        G[A].emplace_back(B, T, K);
        G[B].emplace_back(A, T, K);
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a.second > b.second;    
    };

    priority_queue<pair<int, LL>, vector<pair<int, LL>>, decltype(cmp)> pq(cmp);
    vector<LL> time(N, INF);

    pq.emplace(X, 0LL);
    time[X] = 0LL;
    while(!pq.empty()) {
        pair<int, LL> cur = pq.top();
        pq.pop();

        int v = cur.first;
        LL t = cur.second;

        if(time[v] != t) {
            continue;
        }

        for(auto [nv, c, k] : G[v]) {
            LL wait = (1LL * k - (t % (LL)k)) % (LL)k;
            LL nt = t + wait + (LL)c;
            if(time[nv] > nt) {
                time[nv] = nt;
                pq.emplace(nv, nt);
            }
        }
    }

    cout << (time[Y] == INF ? -1 : time[Y]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
