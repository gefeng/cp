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

const array<int, 4> DR{0, 1, 0, -1};
const array<int, 4> DC{1, 0, -1, 0};

void run_case() {
    int H, W, SR, SC, TR, TC;
    cin >> H >> W >> SR >> SC >> TR >> TC;
    SR -= 1;
    SC -= 1;
    TR -= 1;
    TC -= 1;

    vector<string> G(H);
    for(int i = 0; i < H; i++) {
        cin >> G[i];
    }

    vector<vector<int>> best(H, vector<int>(W, INF));
    deque<array<int, 3>> dq;
    
    dq.push_back({SR, SC, 0});
    best[SR][SC] = 0;

    while(!dq.empty()) {
        array<int, 3> cur = dq.front();
        dq.pop_front();

        int r = cur[0];
        int c = cur[1];
        int w = cur[2];

        if(best[r][c] != w) {
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + DR[i];
            int nc = c + DC[i];
            if(nr >= 0 && nc >= 0 && nr < H && nc < W && G[nr][nc] != '#') {
                if(best[nr][nc] > w) {
                    best[nr][nc] = w;
                    dq.push_front({nr, nc, w});
                }
            }
        }

        for(int i = -2; i <= 2; i++) {
            for(int j = -2; j <= 2; j++) {
                int nr = r + i;
                int nc = c + j;
                if(nr >= 0 && nc >= 0 && nr < H && nc < W && G[nr][nc] != '#') {
                    if(best[nr][nc] > w + 1) {
                        best[nr][nc] = w + 1;
                        dq.push_back({nr, nc, w + 1});
                    }
                }
            }
        }
    }

    cout << (best[TR][TC] == INF ? -1 : best[TR][TC]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
