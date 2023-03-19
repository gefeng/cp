#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const array<int, 4> DR{-1, 1, 1, -1}; // ur, dr, dl, ul
const array<int, 4> DC{1, 1, -1, -1};

void run_case() {
    int N, M, SX, SY, TX, TY;
    cin >> N >> M >> SX >> SY >> TX >> TY;
    SX -= 1;
    SY -= 1;
    TX -= 1;
    TY -= 1;
    
    string D;
    cin >> D;

    int dx = D[0] == 'D' ? 1 : -1;
    int dy = D[1] == 'R' ? 1 : -1;
    int r = SX;
    int c = SY;
    vector<vector<vector<bool>>> vis(4, vector<vector<bool>>(N, vector<bool>(M, false)));
    
    auto is_edge = [&](int r, int c) {
        return r == 0 || c == 0 || r == N - 1 || c == M - 1;
    };

    auto is_corner = [&](int r, int c) {
        return (r == 0 && (c == 0 || c == M - 1)) || (r == N - 1 && (c == 0 || c == M - 1));
    };

    auto set_d = [&] (int dx, int dy) {
        int res = 0;
        for(int i = 0; i < 4; i++) {
            if(dx == DR[i] && dy == DC[i]) {
                res = i;
                break;
            }
        }
        return res;
    };

    int ans = 0;
    int d = set_d(dx, dy);
    while(true) {
        if(r == TX && c == TY) {
            cout << ans << '\n';
            return;
        }
        
        if(vis[d][r][c] && is_edge(r, c)) {
            break;
        }

        vis[d][r][c] = true;

        int nr = r + dx;
        int nc = c + dy;
        if(nr < 0 || nc < 0 || nr >= N || nc >= M) {
            if((nr < 0 && nc < 0) || (nr < 0 && nc >= M) || (nr >= N && nc < 0) || (nr >= N && nc >= M)) {
                dx *= -1;
                dy *= -1;
                d = set_d(dx, dy);
            } else {
                if(nr < 0 || nr >= N) {
                    dx *= -1;
                } else {
                    dy *= -1;
                }
                d = set_d(dx, dy);
            }
            ans += 1;

            nr = r + dx;
            nc = c + dy;
        }

        r = nr;
        c = nc;
        //cout << dx << ' ' << dy << ' ' << r << ' ' << c << '\n';
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
