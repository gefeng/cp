#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int MAX = (int)1e5;
const int INF = (int)2e9;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(MAX + 1, INF));
    dp[0][0] = 0;
    int sum = 0;
    for(int i = 1; i <= N; i++) {
        sum += A[i - 1];
        for(int j = A[i - 1]; j <= MAX; j++) {
            if(dp[i - 1][j - A[i - 1]] != INF) {
                int t = max(j, sum - j);
                dp[i][j] = min(dp[i][j], t);
            }

            if(sum - j >= 0 && dp[i - 1][sum - j] != INF) {
                int t = max(j, sum - j);
                dp[i][j] = min(dp[i][j], t);
            } 
        }
    }

    int ans = INF;
    for(int i = 0; i <= MAX; i++) {
        ans = min(ans, dp[N][i]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
