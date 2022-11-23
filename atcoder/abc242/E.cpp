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
    string S;

    cin >> N >> S;
    
    if(N == 1) {
        cout << S[0] - 'A' + 1 << '\n';
        return;
    }

    vector<vector<LL>> dp(N / 2 + 1, vector<LL>(2, 0LL));
    dp[1][0] = S[0] - 'A';
    dp[1][1] = 1LL;

    for(int i = 2; i <= N / 2; i++) {
        dp[i][0] += dp[i - 1][0] * 26LL % MOD;
        dp[i][0] %= MOD;

        dp[i][0] += dp[i - 1][1] * (S[i - 1] - 'A') % MOD;
        dp[i][0] %= MOD;

        dp[i][1] += dp[i - 1][1];
        dp[i][1] %= MOD;
    }

    LL ans = 0LL;
    
    if(N & 1) {
        ans += dp[N / 2][0] * 26LL % MOD;
        ans %= MOD;
        ans += dp[N / 2][1] * (S[N / 2] - 'A') % MOD;
        ans %= MOD;
        
        string prefix = S.substr(0, N / 2);
        string suffix = prefix;
        reverse(suffix.begin(), suffix.end());
        
        prefix.push_back(S[N / 2]);
        if(prefix + suffix <= S) {
            ans += 1LL;
            ans %= MOD;
        }
    } else {
        ans += dp[N / 2][0];
        ans %= MOD;
        ans += dp[N / 2][1];
        ans %= MOD;
        
        string prefix = S.substr(0, N / 2);
        string suffix = prefix;
        reverse(suffix.begin(), suffix.end());
        
        if(prefix + suffix > S) {
            ans -= 1LL;
            ans += MOD;
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
