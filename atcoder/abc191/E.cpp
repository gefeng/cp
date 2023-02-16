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

    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        A -= 1;
        B -= 1;

        G[A].emplace_back(B, C);
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a.second > b.second;
    };

    for(int i = 0; i < N; i++) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp); 
        vector<int> dp(N, INF);

        pq.emplace(i, 0);
        dp[i] = 0;

        int ans = INF;
        while(!pq.empty()) {
            pair<int, int> cur = pq.top();
            pq.pop();
            int v = cur.first;
            int t = cur.second;

            if(dp[v] != t) {
                continue;
            }

            for(pair<int, int> nei : G[v]) {
                int nv = nei.first;
                int nt = nei.second + t;
                if(nt < dp[nv]) {
                    dp[nv] = nt;
                    pq.emplace(nv, nt);
                }
                if(nv == i) {
                    ans = min(ans, nt);
                }
            }
        }

        cout << (ans == INF ? -1 : ans) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
