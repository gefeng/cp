#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const int MOD = 998244353;

void run_case() {
    string N;
    cin >> N;

    int M;
    cin >> M;

    int A = 0;
    for(int i = 0; i < M; i++) {
        int X;
        cin >> X;
        A |= 1 << X;
    }

    int len = N.length();
    vector<vector<int>> dp(vector<vector<int>>(1 << 10, vector<int>(2, 0)));
    vector<vector<int>> ds(vector<vector<int>>(1 << 10, vector<int>(2, 0)));
    
    for(int x = 1; x < N[0] - '0'; x++) {
        dp[1 << x][1] = 1;
        ds[1 << x][1] = x;
    }
    dp[0][1] = 1;
    dp[1 << (N[0] - '0')][0] = 1;
    ds[1 << (N[0] - '0')][0] = N[0] - '0';

    for(int i = 1; i < len; i++) {
        vector<vector<int>> ndp(vector<vector<int>>(1 << 10, vector<int>(2, 0)));
        vector<vector<int>> nds(vector<vector<int>>(1 << 10, vector<int>(2, 0)));
        
        int d = N[i] - '0';
        for(int s = 0; s < 1024; s++) {
            for(int j = 0; j < 2; j++) {
                LL cnt = dp[s][j];
                LL sum = ds[s][j];
                for(int x = 0; x < 10; x++) {
                    int ns = (x == 0 && s == 0) ? 0 : s | (1 << x);
                    int nj = j;

                    if(j == 0) {
                        if(x > d) {
                            break;
                        }
                        if(x < d) {
                            nj = 1;
                        }
                    }

                    ndp[ns][nj] += cnt;
                    ndp[ns][nj] %= MOD;

                    nds[ns][nj] += ((sum * 10LL % MOD) + (cnt * x % MOD)) % MOD;
                    nds[ns][nj] %= MOD; 
                }
            } 
        }

        swap(dp, ndp);
        swap(ds, nds);
    }

    int ans = 0;
    for(int s = 0; s < 1024; s++) {
        for(int j = 0; j < 2; j++) {
            if((s & A) == A) {
                ans += ds[s][j];
                ans %= MOD;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
