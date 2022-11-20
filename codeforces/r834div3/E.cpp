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
    int N, H;
    cin >> N >> H;

    vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<vector<vector<LL>>> dp(N + 1, vector<vector<LL>>(3, vector<LL>(2, 0LL)));
    for(int i = 0; i <= 2; i++) {
        for(int j = 0; j <= 1; j++) {
            dp[0][i][j] = H * pow(2, i) * pow(3, j);
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= 2; j++) {
            for(int k = 0; k <= 1; k++) {
                for(int s = 0; s <= j; s++) {
                    for(int t = 0; t <= k; t++) {
                        LL pre = dp[i - 1][s][t];
                        LL cur = pre * pow(2LL, j - s) * pow(3LL, k - t);
                        if(cur > A[i - 1]) {
                            dp[i][j][k] = max(dp[i][j][k], cur + A[i - 1] / 2);
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        LL x = -1LL;
        for(int j = 0; j <= 2; j++) {
            for(int k = 0; k <= 1; k++) {
                x = max(x, dp[i][j][k]);
            }
        }

        if(x <= A[i - 1])  {
            break;
        }
        ans = i;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
