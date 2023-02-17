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
    int N;
    cin >> N;

    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<LL>> dp(N + 1, vector<LL>(2, 0LL));
    dp[1][0] = A[0] == "AND" ? 3LL : 1LL;
    dp[1][1] = A[0] == "AND" ? 1LL : 3LL;
    for(int i = 2; i <= N; i++) {
        if(A[i - 1] == "AND") {
            dp[i][0] += dp[i - 1][0] * 2LL;
            dp[i][0] += dp[i - 1][1];
            dp[i][1] += dp[i - 1][1];
        } else {
            dp[i][0] += dp[i - 1][0];
            dp[i][1] += dp[i - 1][0];
            dp[i][1] += dp[i - 1][1] * 2LL;
        }
    }

    cout << dp[N][1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
