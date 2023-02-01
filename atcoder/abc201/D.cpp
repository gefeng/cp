#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int INF = (int)2e9;

int dfs(vector<string>& G, int H, int W, int r, int c, vector<vector<int>>& dp) {
    if(r == H - 1 && c == W - 1) {
        return 0;
    } 

    if(dp[r][c] != -1) {
        return dp[r][c];
    }

    int best = -INF;
    if(r + 1 < H) {
        int s = G[r + 1][c] == '+' ? 1 : -1;
        int res = dfs(G, H, W, r + 1, c, dp);
        best = max(best, s - res);
    }
    if(c + 1 < W) {
        int s = G[r][c + 1] == '+' ? 1 : -1;
        int res = dfs(G, H, W, r, c + 1, dp);
        best = max(best, s - res);
    }
    
    return dp[r][c] = best;
}

void run_case() {
    int H, W;
    cin >> H >> W;
    
    vector<string> G(H);
    for(int i = 0; i < H; i++) {
        cin >> G[i];
    }

    vector<vector<int>> dp(H, vector<int>(W, -1));
    int ans = dfs(G, H, W, 0, 0, dp); 

    if(ans == 0) {
        cout << "Draw" << '\n';
    } else if(ans > 0) {
        cout << "Takahashi" << '\n';
    } else {
        cout << "Aoki" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
