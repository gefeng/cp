#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    vector<vector<int>> G(H, vector<int>(W, 0));
    for(int i = 0; i < N; i++) {
        int R, C;
        cin >> R >> C;
        G[R - 1][C - 1] = 1;
    }

    for(int i = 0; i < M; i++) {
        int R, C;
        cin >> R >> C;
        G[R - 1][C - 1] = 2;
    }

    vector<vector<bool>> illuminated(H, vector<bool>(W, false));

    for(int i = 0; i < H; i++) {
        bool flag = false;
        for(int j = 0; j < W; j++) {
            if(G[i][j] == 1) {
                flag = true;
            } else if(G[i][j] == 2) {
                flag = false;
            }
            illuminated[i][j] = illuminated[i][j] || flag;
        }
    }

    for(int i = H - 1; i >= 0; i--) {
        bool flag = false;
        for(int j = W - 1; j >= 0; j--) {
            if(G[i][j] == 1) {
                flag = true;
            } else if(G[i][j] == 2) {
                flag = false;
            }
            illuminated[i][j] = illuminated[i][j] || flag;
        }
    }

    for(int i = 0; i < W; i++) {
        bool flag = false;
        for(int j = 0; j < H; j++) {
            if(G[j][i] == 1) {
                flag = true;
            } else if(G[j][i] == 2) {
                flag = false;
            }
            illuminated[j][i] = illuminated[j][i] || flag;
        }
    }

    for(int i = W - 1; i >= 0; i--) {
        bool flag = false;
        for(int j = H - 1; j >= 0; j--) {
            if(G[j][i] == 1) {
                flag = true;
            } else if(G[j][i] == 2) {
                flag = false;
            }
            illuminated[j][i] = illuminated[j][i] || flag;
        }
    }

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(illuminated[i][j]) {
                ans += 1;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
