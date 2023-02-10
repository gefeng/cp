#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int to_int(vector<vector<int>>& G, int H, int W) {
    int res = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j]) {
                res |= 1 << (i * W + j);
            }
        } 
    } 
    return res;
}

int dfs(vector<vector<int>>& G, int H, int W, int A, int r, int c) {
    if(A == 0) {
        return 1;
    }

    if(r == H) {
        return 0;
    }
    if(c == W) {
        return dfs(G, H, W, A, r + 1, 0);
    }

    if(G[r][c] == 1) {
        return dfs(G, H, W, A, r, c + 1);
    }

    int res = 0;

    res += dfs(G, H, W, A, r, c + 1);
    
    if(r < H - 1 && G[r + 1][c] != 1) {
        G[r][c] = 1;
        G[r + 1][c] = 1;
        res += dfs(G, H, W, A - 1, r, c + 1);
        G[r][c] = 0;
        G[r + 1][c] = 0;
    } 
    if(c < W - 1 && G[r][c + 1] != 1) {
        G[r][c] = 1;
        G[r][c + 1] = 1;
        res += dfs(G, H, W, A - 1, r, c + 2);
        G[r][c] = 0;
        G[r][c + 1] = 0;
    }
    return res;
}

void run_case() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<vector<int>> G(H, vector<int>(W, 0));

    cout << dfs(G, H, W, A, 0, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
