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
    int N, K, D;
    cin >> N >> K >> D;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<vector<LL>>> dp(N + 1, vector<vector<LL>>(K + 1, vector<LL>(D, -1LL)));
    for(int i = 0; i <= K; i++) {
        dp[i][0][0] = 0LL;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= K; j++) {
            for(int r = 0; r < D; r++) {
                if(dp[i][j][r] != -1LL) {
                    dp[i + 1][j][r] = max(dp[i + 1][j][r], dp[i][j][r]);
                }
                if(dp[i][j][r] != -1 && j + 1 <= K) {
                    dp[i + 1][j + 1][(A[i] + r) % D] = max(dp[i + 1][j + 1][(A[i] + r) % D], dp[i][j][r] + A[i]);
                }
            } 
        }
    }

    cout << dp[N][K][0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
