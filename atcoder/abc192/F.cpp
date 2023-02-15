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
    int N;
    cin >> N;

    LL X;
    cin >> X;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = INF;
    for(int k = 1; k <= N; k++) {
        vector<vector<LL>> dp(k + 1, vector<LL>(k, -1LL));
        dp[0][0] = 0LL;
        for(int x : A) {
            for(int i = k - 1; i >= 0; i--) {
                for(int r = 0; r < k; r++) {
                    if(dp[i][r] != -1) {
                        dp[i + 1][(r + x) % k] = max(dp[i + 1][(r + x) % k], dp[i][r] + x);
                    }
                }
            }
        }

        if(dp[k][X % k] != -1LL) {
            ans = min(ans, (X - dp[k][X % k]) / k);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
