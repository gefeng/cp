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
    //1 2 3 4 12 13 14 23 24 34 134 124 234
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<vector<LL>> dp(1024, vector<LL>(10, 0LL)); 

    for(int i = 0; i < N; i++) {
        int c = S[i] - 'A';
        vector<vector<LL>> ndp(1024, vector<LL>(10, 0LL));

        ndp[1 << c][c] = 1LL;
        
        for(int j = 0; j < 1024; j++) {
            for(int k = 0; k < 10; k++) {
                ndp[j][k] += dp[j][k];
                ndp[j][k] %= MOD;

                if(j & (1 << k)) {
                    if(j & (1 << c)) {
                        if(k == c) {
                            ndp[j][k] += dp[j][k];
                            ndp[j][k] %= MOD;
                        } 
                    } else {
                        ndp[j | (1 << c)][c] += dp[j][k];
                        ndp[j | (1 << c)][c] %= MOD;
                    }
                }
            }            
        }
        swap(dp, ndp);
    }

    LL ans = 0LL;
    for(int i = 1; i < 1024; i++) {
        for(int j = 0; j < 10; j++) {
            ans += dp[i][j];
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
