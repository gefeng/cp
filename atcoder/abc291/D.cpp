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

    vector<int> A(N);
    vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    vector<vector<LL>> dp(2, vector<LL>(N + 1, 0LL));
    dp[0][1] = 1LL;
    dp[1][1] = 1LL;
    
    for(int i = 2; i <= N; i++) {
        if(A[i - 1] != A[i - 2]) {
            dp[0][i] += dp[0][i - 1];
            dp[0][i] %= MOD;
        }
        if(A[i - 1] != B[i - 2]) {
            dp[0][i] += dp[1][i - 1];
            dp[0][i] %= MOD;
        }
        if(B[i - 1] != A[i - 2]) {
            dp[1][i] += dp[0][i - 1];
            dp[1][i] %= MOD;
        }
        if(B[i - 1] != B[i - 2]) {
            dp[1][i] += dp[1][i - 1];
            dp[1][i] %= MOD;
        }
    }

    cout << (dp[0][N] + dp[1][N]) % MOD << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
