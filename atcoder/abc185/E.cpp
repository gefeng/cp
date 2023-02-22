#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for(int i = 0; i <= N; i++) {
        dp[i][0] = i;
    }
    for(int i = 0; i <= M; i++) {
        dp[0][i] = i;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;

            if(A[i - 1] == B[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            } else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }

    cout << dp[N][M] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
