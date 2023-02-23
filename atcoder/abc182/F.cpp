#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL dfs(vector<LL>& A, vector<LL>& v, int i, int c, vector<vector<LL>>& dp) {
    if(i == A.size()) {
        return 1LL;
    }

    if(dp[c][i] != -1LL) {
        return dp[c][i];
    }

    LL res = 0LL;
    if(i == A.size() - 1) {
        res = dfs(A, v, i + 1, 0, dp);
    } else {
        LL max_use = A[i + 1] / A[i] - 1LL;
        if(c == 0) {
            if(v[i] != 0) {
                res += dfs(A, v, i + 1, 1, dp);
            }
            res += dfs(A, v, i + 1, 0, dp);
        } else {
            if(v[i] == max_use) {
                res += dfs(A, v, i + 1, 1, dp);     
            } else {
                res += dfs(A, v, i + 1, 1, dp);
                res += dfs(A, v, i + 1, 0, dp);
            }
        }
    }

    return dp[c][i] = res;
}

void run_case() {
    int N; 
    LL X;
    cin >> N >> X;

    vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<LL> v(N);
    for(int i = N - 1; i >= 0; i--) {
        v[i] = X / A[i];
        X -= v[i] * A[i];
    }

    vector<vector<LL>> dp(2, vector<LL>(N, -1LL));
    LL res = dfs(A, v, 0, 0, dp);

    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
