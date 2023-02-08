#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    X -= 1;
    Y -= 1;

    vector<string> G(H);
    for(int i = 0; i < H; i++) {
        cin >> G[i];
    }

    int ans = 1;
    for(int c = Y - 1; c >= 0; c--) {
        if(G[X][c] != '#') {
            ans += 1;
        } else {
            break;
        }
    }

    for(int c = Y + 1; c < W; c++) {
        if(G[X][c] != '#') {
            ans += 1;
        } else {
            break;
        }
    }

    for(int r = X - 1; r >= 0; r--) {
        if(G[r][Y] != '#') {
            ans += 1;
        } else {
            break;
        }
    }

    for(int r = X + 1; r < H; r++) {
        if(G[r][Y] != '#') {
            ans += 1;
        } else {
            break;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
