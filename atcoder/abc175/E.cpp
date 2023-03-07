#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int R, C, K;
    cin >> R >> C >> K;

    vector<vector<int>> G(R, vector<int>(C, 0));
    for(int i = 0; i < K; i++) {
        int R, C, V;
        cin >> R >> C >> V;
        R -= 1;
        C -= 1;
        G[R][C] = V;
    }

    vector<vector<vector<LL>>> dp(4, vector<vector<LL>>(R, vector<LL>(C, 0LL)));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            for(int k = 0; k < 4; k++) {
                if(j + 1 < C) {
                    dp[k][i][j + 1] = max(dp[k][i][j + 1], dp[k][i][j]);
                    if(k < 3) {
                        dp[k + 1][i][j + 1] = max(dp[k + 1][i][j + 1], dp[k][i][j] + G[i][j]);
                    }
                }

                if(i + 1 < R) {
                    dp[0][i + 1][j] = max(dp[0][i + 1][j], dp[k][i][j]);
                    if(k < 3) {
                        dp[0][i + 1][j] = max(dp[0][i + 1][j], dp[k][i][j] + G[i][j]);
                    }
                }
            }
        }
    }

    LL ans = 0LL;
    for(int i = 0; i < 4; i++) {
        ans = max(ans, dp[i][R - 1][C - 1] + (i == 3 ? 0 : G[R - 1][C - 1]));
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
