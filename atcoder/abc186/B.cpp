#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> G(H, vector<int>(W, 0));
    int min_v = 100;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> G[i][j];
            min_v = min(min_v, G[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            ans += G[i][j] - min_v;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
