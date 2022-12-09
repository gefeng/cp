#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int INF = 1e9;

void run_case() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }


    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(X + 1, vector<int>(Y + 1, INF)));
    for(int i = 0; i <= N; i++) {
        dp[i][0][0] = 0;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= X; j++) {
            for(int k = 0; k <= Y; k++) {
                int nj = min(X, j + A[i].first);
                int nk = min(Y, k + A[i].second);
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
                dp[i + 1][nj][nk] = min(dp[i + 1][nj][nk], dp[i][j][k] + 1);
            }
        }
    }

    cout << (dp[N][X][Y] >= INF ? -1 : dp[N][X][Y]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
