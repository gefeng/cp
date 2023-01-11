#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;

void run_case() {
    int H, W;
    LL C;
    cin >> H >> W >> C;

    vector<vector<LL>> G(H, vector<LL>(W, 0LL));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> G[i][j];
        }
    }

    LL ans = INF;

    for(int rep = 0; rep < 2; rep++) {
    
        vector<vector<LL>> dp(H, vector<LL>(W, INF));
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                dp[i][j] = G[i][j];
                if(i > 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + C);
                }
                if(j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + C);
                } 
            }
        }

        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                LL cost = INF;
                if(i > 0 && dp[i - 1][j] != INF) {
                    cost = min(cost, dp[i - 1][j] + C + G[i][j]);
                }
                if(j > 0 && dp[i][j - 1] != INF) {
                    cost = min(cost, dp[i][j - 1] + C + G[i][j]);
                }
                ans = min(ans, cost);
            }
        }

        reverse(G.begin(), G.end());
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
