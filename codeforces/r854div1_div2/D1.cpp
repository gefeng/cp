#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;

void run_case() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<LL> C(K + 1);
    vector<LL> H(K + 1);
    for(int i = 1; i <= K; i++) {
        cin >> C[i];
    }

    for(int i = 1; i <= K; i++) {
        cin >> H[i];
    }
    
    vector<vector<LL>> dp(N + 1, vector<LL>(K + 1, INF));
    dp[1][0] = C[A[0]];
    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= K; j++) {
            if(dp[i][j] != INF) {
                // run program A[i] on the CPU on which program j run
                
                dp[i + 1][A[i - 1]] = min(dp[i + 1][A[i - 1]], dp[i][j] + (A[i] == j ? H[A[i]] : C[A[i]]));

                // run program A[i] on the other CPU
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (i == 0 || A[i] != A[i - 1] ? C[A[i]] : H[A[i]]));
            }
        }
    } 

    LL ans = INF;
    for(int i = 0; i <= K; i++) {
        ans = min(ans, dp[N][i]);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
