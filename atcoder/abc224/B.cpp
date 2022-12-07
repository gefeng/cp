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
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> G[i][j];
        }
    }
    
    for(int i = 0; i < H - 1; i++) {
        for(int j = 0; j < W - 1; j++) {
            if(G[i][j] + G[i + 1][j + 1] > G[i + 1][j] + G[i][j + 1]) {
                cout << "No" << '\n';
                return;
            }
        }
    }

    cout << "Yes" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
