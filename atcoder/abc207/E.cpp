#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7LL;

void run_case() {
    int N;
    cin >> N;

    vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<LL> psum(N + 1, 0LL);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    vector<vector<LL>> dp(N + 1, vector<LL>(N + 1, 0LL));
    vector<vector<LL>> ds(N + 1, vector<LL>(N + 1, 0LL));
    dp[0][0] = 1LL;
    ds[0][0] = 1LL;
    
    for(int i = 1; i <= N; i++) {
        for(int j = i; j >= 1; j--) {
            /*for(int k = i; k >= 1; k--) {
                sum += A[k - 1];  
                if(sum % j == 0LL) {
                    dp[i][j] += dp[k - 1][j - 1];
                    dp[i][j] %= MOD;
                }
            }*/

            // (psum[i] - psum[k]) % j == 0 -> psum[i] % j == psum[k] % j
            LL sum = ds[j - 1][psum[i] % j];
            dp[i][j] = sum;
            ds[j][psum[i] % (j + 1)] += sum;
            ds[j][psum[i] % (j + 1)] %= MOD;
            //cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }

    LL ans = 0LL;
    for(int i = 1; i <= N; i++) {
        ans += dp[N][i]; 
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
