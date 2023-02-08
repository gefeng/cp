#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int dfs(string& S, string& X, int N, int cur, int rem, vector<vector<int>>& dp) {
    if(cur == N) {
        return rem == 0 ? 0 : 1;
    }

    if(dp[rem][cur] != -1) {
        return dp[rem][cur];
    }

    int t = X[cur] == 'T' ? 0 : 1;
    
    if(t == 0) {
        for(int i : {0, S[cur] - '0'}) {
            int res = dfs(S, X, N, cur + 1, (rem * 10 % 7 + i) % 7, dp);    
            if(res == 0) {
                dp[rem][cur] = 0;
                return 0;
            }
        }
        dp[rem][cur] = 1;
        return 1;
    } else {
        for(int i : {0, S[cur] - '0'}) {
            int res = dfs(S, X, N, cur + 1, (rem * 10 % 7 + i) % 7, dp);    
            if(res == 1) {
                dp[rem][cur] = 1;
                return 1;
            }
        }
        dp[rem][cur] = 0;
        return 0;
    }
}

void run_case() {
    int N;
    cin >> N;

    string S, X;
    cin >> S >> X;

    vector<vector<int>> dp(7, vector<int>(N, -1));
    int res = dfs(S, X, N, 0, 0, dp);

    cout << (res == 0 ? "Takahashi" : "Aoki") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
