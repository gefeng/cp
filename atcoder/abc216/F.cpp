#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = 998244353LL;

void run_case() {
    int N;
    cin >> N;


    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        cin >> A[i].second;
    }
    

    sort(A.begin(), A.end());

    vector<vector<LL>> dp(N + 1, vector<LL>(5001, 0LL));
    dp[0][0] = 1LL;

    LL ans = 0LL;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= 5000; j++) {
            dp[i][j] = dp[i - 1][j];

            if(j - A[i - 1].second >= 0) {
                dp[i][j] += dp[i - 1][j - A[i - 1].second];
                dp[i][j] %= MOD;

                if(j <= A[i - 1].first) {
                    ans += dp[i - 1][j - A[i - 1].second];
                    ans %= MOD;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
