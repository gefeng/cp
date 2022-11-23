#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    
    vector<vector<int>> G(H, vector<int>(W, 0));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> G[i][j];
        }
    }

    vector<vector<vector<int>>> psum(N + 1, vector<vector<int>>(H + 1, vector<int>(W + 1, 0)));
    for(int i = 1; i <= N; i++) {
        vector<vector<int>>& v = psum[i];
        for(int r = 1; r <= H; r++) {
            for(int c = 1; c <= W; c++) {
                v[r][c] = v[r - 1][c] + v[r][c - 1] - v[r - 1][c - 1] + (G[r - 1][c - 1] == i ? 1 : 0);
            }
        }
    }

    for(int k = 0; k <= H - h; k++) {
        for(int l = 0; l <= W - w; l++) {
            int x = k + h - 1;
            int y = l + w - 1;
            
            int ans = 0;
            for(int i = 1; i <= N; i++) {
                vector<vector<int>>& v = psum[i];
                int cnt = v[H][W] - (v[x + 1][y + 1] - v[k][y + 1] - v[x + 1][l] + v[k][l]);
                if(cnt) {
                    ans += 1;
                }
            } 

            cout << ans << " \n"[l == W - w];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
