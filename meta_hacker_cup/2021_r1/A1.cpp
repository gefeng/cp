#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int INF = (int)1e6;

void dpSol(int T) {
    int N;
    string S;
    cin >> N >> S;

    vector<vector<int>> dp(N + 1, vector<int>(2, INF));
    
    dp[0][0] = 0;
    dp[0][1] = 0;

    for(int i = 1; i <= N; i++) {
        if(S[i - 1] == 'F') {
            if(dp[i - 1][0] != INF) {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][0] + 1;
            }
            if(dp[i - 1][1] != INF) {
                dp[i][1] = min(dp[i][1], dp[i - 1][1]);
                dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
            }
        }
        if(S[i - 1] == 'O') {
            if(dp[i - 1][1] != INF) {
                dp[i][1] = dp[i - 1][1];
            }
            if(dp[i - 1][0] != INF) {
                dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
            }
        }
        if(S[i - 1] == 'X') {
            if(dp[i - 1][0] != INF) {
                dp[i][0] = dp[i - 1][0];
            }
            if(dp[i - 1][1] != INF) {
                dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
            }
        }
    }

    cout << "Case #" << T << ": " << min(dp[N][0], dp[N][1]) << '\n';
}

void run_case(int T) {
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    int cur = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'F' || (S[i] == 'X' && cur == 0) || (S[i] == 'O' && cur == 1)) {
            continue;
        }

        if(cur == -1) {
            cur = S[i] == 'X' ? 0 : 1;
        } else {
            ans++;
            cur ^= 1;
        }
    }

    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
