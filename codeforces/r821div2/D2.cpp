#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, X, Y;
    cin >> N >> X >> Y;
   
    string A, B;
    cin >> A >> B;

    // either do a sequence of X or just do Y
    vector<int> d; 
    d.reserve(N);
    for(int i = 0; i < N; i++) {
        if(A[i] != B[i]) {
            d.push_back(i);
        } 
    }

    int n = d.size();
    if(n & 1) {
        cout << -1 << '\n';
        return;
    }

    if(X >= Y) {
        LL ans = 0LL;
        int pre = -1;
        int cnt = 0;
        int adj = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] == B[i]) {
                continue;
            }

            if(pre == -1) {
                pre = i;
            } else {
                if(pre + 1 == i) {
                    adj++;
                }
                pre = -1;
            }
            cnt++;
        }

        if(cnt == 2) {
            if(X < 2 * Y) {
                ans = adj ? X : Y;
            } else {
                ans = adj ? 2 * Y : Y;
            }
        } else {
            ans = (LL)cnt / 2LL * (LL)Y;
        }

        cout << ans << '\n';
    } else {
        vector<LL> dp(n + 1, -1LL);
        dp[0] = 0LL; 
        dp[1] = 0LL; 
        for(int i = 2; i <= n; i++) {
            if(i & 1) {
                dp[i] = min(dp[i - 2] + 1LL * X * (d[i - 1] - d[i - 2]), dp[i - 1]);
                if(d[i - 1] - d[i - 2] == 1) {
                    dp[i] = min(dp[i], dp[i - 2] + 1LL * Y);        
                }
            } else {
                dp[i] = min(dp[i - 2] + 1LL * X * (d[i - 1] - d[i - 2]), dp[i - 1] + Y);
                if(d[i - 1] - d[i - 2] == 1) {
                    dp[i] = min(dp[i], dp[i - 2] + 1LL * Y);        
                }
            }
        }

        cout << dp[n] << '\n';
    }
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
