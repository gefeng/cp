#include <iostream>
#include <array>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = 998244353LL;

void run_case() {
    int N, D;
    cin >> N >> D;

    vector<int> P(N, 0);
    vector<int> Q(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> Q[i];
    }

    // dp[i][j] i: d(p, r) j: d(q, r)
    vector<vector<LL>> dp(D + 1, vector<LL>(D + 1, 0));
    dp[0][0] = 1;
    for(int k = 1; k <= N; k++) {
        vector<vector<LL>> ndp(D + 1, vector<LL>(D + 1, 0));
        vector<vector<LL>> psum_diag1(D + 1, vector<LL>(D + 1, 0));
        vector<vector<LL>> psum_diag2(D + 1, vector<LL>(D + 1 ,0));

        for(int i = 0; i <= D; i++) {
            for(int j = 0; j <= D; j++) {
                psum_diag1[i][j] = dp[i][j];
                if(i && j) {
                    psum_diag1[i][j] += psum_diag1[i - 1][j - 1];
                    psum_diag1[i][j] %= MOD;
                }

                psum_diag2[i][j] = dp[i][j];
                if(i && (j + 1 <= D)) {
                    psum_diag2[i][j] += psum_diag2[i - 1][j + 1];
                    psum_diag2[i][j] %= MOD;
                }
            }
        }

        for(int i = 0; i <= D; i++) {
            for(int j = 0; j <= D; j++) {
                int d = abs(P[k - 1] - Q[k - 1]);
                
                int x = i;
                int y = j - d;
                if(y < 0) {
                    x = i - d + j;
                    y = 0;
                }
                if(x >= 0 && x <= D && y >= 0 && y <= D) {
                    ndp[i][j] += psum_diag2[x][y];
                    ndp[i][j] %= MOD;

                }
                if(i - d - 1 >= 0 && j + 1 <= D) {
                    ndp[i][j] -= psum_diag2[i - d - 1][j + 1];
                    ndp[i][j] += MOD;
                    ndp[i][j] %= MOD;
                }

                if(i - d - 1 >= 0 && j - 1 >= 0) {
                    ndp[i][j] += psum_diag1[i - d - 1][j - 1];
                    ndp[i][j] %= MOD;
                }
                if(j - d - 1 >= 0 && i - 1 >= 0) {
                    ndp[i][j] += psum_diag1[i - 1][j - d - 1];
                    ndp[i][j] %= MOD;
                }
                
                //cout << i << ' ' << j << ' ' << ndp[i][j] << '\n';
            }
        }

        dp = ndp;
    }

    LL ans = 0;
    for(int i = 0; i <= D; i++) {
        for(int j = 0; j <= D; j++) {
            ans += dp[i][j];
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    run_case();
}
