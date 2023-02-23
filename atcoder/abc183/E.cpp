#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7LL;

void run_case() {
    int H, W;
    cin >> H >> W;

    vector<string> G(H);
    for(int i = 0; i < H; i++) {
        cin >> G[i];
    }

    vector<vector<LL>> ds1(H + 1, vector<LL>(W + 1, 0LL));
    vector<vector<LL>> ds2(H + 1, vector<LL>(W + 1, 0LL));
    vector<vector<LL>> ds3(H + 1, vector<LL>(W + 1, 0LL));
    vector<vector<LL>> dp(H, vector<LL>(W, 0LL));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == '#') {
                continue;
            }

            if(i == 0 && j == 0) {
                dp[i][j] = 1LL;
            } else {
                dp[i][j] += ds1[i + 1][j];
                dp[i][j] %= MOD;
                dp[i][j] += ds2[i][j + 1];
                dp[i][j] %= MOD;
                dp[i][j] += ds3[i][j];
                dp[i][j] %= MOD;
            }

            ds1[i + 1][j + 1] = ds1[i + 1][j] + dp[i][j] % MOD;
            ds2[i + 1][j + 1] = ds2[i][j + 1] + dp[i][j] % MOD;
            ds3[i + 1][j + 1] = ds3[i][j] + dp[i][j] % MOD;
        }
    } 

    cout << dp[H - 1][W - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
