#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int INF = 2e9;
const array<int, 4> DR{1, -1, 1, -1};
const array<int, 4> DC{1, 1, -1, -1};

void run_case() {
    int N;
    cin >> N;

    int A_X, A_Y, B_X, B_Y;
    cin >> A_X >> A_Y >> B_X >> B_Y;

    vector<string> G(N);
    for(int i = 0; i < N; i++) {
        cin >> G[i];
    }

    deque<array<int, 4>> q;
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(4, INF)));
    
    for(int i = 0; i < 4; i++) {
        q.push_back({A_X - 1, A_Y - 1, i, 0});
        dist[A_X - 1][A_Y - 1][i] = 0;
    }

    while(q.size()) {
        array<int, 4> cur = q.front();
        q.pop_front();

        if(dist[cur[0]][cur[1]][cur[2]] != cur[3]) {
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int nr = cur[0] + DR[i];
            int nc = cur[1] + DC[i];
            if(nr >= 0 && nc >= 0 && nr < N && nc < N && G[nr][nc] != '#') {
                int nd = i == cur[2] ? cur[3] : cur[3] + 1;

                if(dist[nr][nc][i] > nd) {
                    dist[nr][nc][i] = nd;
                    if(nd == cur[3]) {
                        q.push_front({nr, nc, i, nd});
                    } else {
                        q.push_back({nr, nc, i, nd});
                    }
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < 4; i++) {
        ans = min(ans, dist[B_X - 1][B_Y - 1][i]);
    }
    cout << (ans == INF ? -1 : ans + 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
