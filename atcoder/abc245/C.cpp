#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    vector<int> B(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(2, false));
    dp[1][0] = true;
    dp[1][1] = true;

    for(int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] && abs(A[i - 2] - A[i - 1]) <= K) || (dp[i - 1][1] && abs(B[i - 2] - A[i - 1]) <= K);
        dp[i][1] = (dp[i - 1][0] && abs(A[i - 2] - B[i - 1]) <= K) || (dp[i - 1][1] && abs(B[i - 2] - B[i - 1]) <= K);
    }

    cout << (dp[N][0] || dp[N][1] ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
