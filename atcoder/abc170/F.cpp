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
const array<int, 4> DR{0, 1, 0, -1};
const array<int, 4> DC{1, 0, -1, 0};

void run_case() {
    int H, W, K;
    cin >> H >> W >> K;

    int SX, SY, TX, TY;
    cin >> SX >> SY >> TX >> TY;
    SX -= 1;
    SY -= 1;
    TX -= 1;
    TY -= 1;

    vector<string> G(H);
    for(int i = 0; i < H; i++) {
        cin >> G[i];
    }

    auto cmp = [](const auto& a, const auto& b) {
        return a[3] > b[3];
    };

    priority_queue<array<LL, 4>, vector<array<LL, 4>>, decltype(cmp)> pq(cmp);
    vector<vector<vector<LL>>> best(H, vector<vector<LL>>(W, vector<LL>(4, INF)));

    for(int i = 0; i < 4; i++) {
        best[SX][SY][i] = 0LL;
        pq.push({SX, SY, i, 0LL});
    }
    

    while(!pq.empty()) {
        array<LL, 4> cur = pq.top();
        pq.pop();

        int r = cur[0];
        int c = cur[1];
        int d = cur[2];
        LL cost = cur[3];

        if(cost != best[r][c][d]) {
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + DR[i];
            int nc = c + DC[i];
            if(nr >= 0 && nc >= 0 && nr < H && nc < W && G[nr][nc] != '@') {
                LL ncost = cost;
                if(d == -1 || d == i) {
                    ncost += 1LL;
                } else {
                    ncost = (cost + K - 1LL) / K * K + 1LL;
                }
                if(best[nr][nc][i] > ncost) {
                    best[nr][nc][i] = ncost;
                    pq.push({nr, nc, i, ncost});
                }
            }
        }
    }

    LL ans = INF;
    for(int i = 0; i < 4; i++) {
        if(best[TX][TY][i] != INF) {
            ans = min(ans, (best[TX][TY][i] + K - 1LL) / K);
        }
    }

    cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
