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

    vector<vector<int>> M(H, vector<int>(W, 0));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> M[i][j];
        }
    }

    vector<vector<int>> ans(W, vector<int>(H, 0));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            ans[j][i] = M[i][j];
        }
    }

    for(int i = 0; i < W; i++) {
        for(int j = 0; j < H; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
