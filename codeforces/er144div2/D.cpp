#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;

void run_case() {
    int N, K, X;
    cin >> N >> K >> X;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = 0LL;
    vector<vector<LL>> dp(N + 1, vector<LL>(K + 1, -INF));
    dp[0][0] = 0LL;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= min(K, i); j++) {
            if(j <= i - 1) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + A[i - 1] - X);
            }
            if(j > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + A[i - 1] + X);
            }

            if(N - i >= K - j) {
                ans = max(ans, dp[i][j]);
            }
            dp[i][j] = max(0LL, dp[i][j]);
        } 
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
