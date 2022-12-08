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
        cin >> A[i];
    }
    
    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    vector<LL> dp(3001, 0LL);
    vector<LL> ds(3002, 0LL);
    for(int i = A[0]; i <= B[0]; i++) {
        dp[i] = 1LL;
        ds[i + 1] = ds[i] + 1LL;
    }

    for(int i = 2; i <= N; i++) {
        vector<LL> ndp(3001, 0LL);
        
        for(int j = A[i - 1]; j <= B[i - 1]; j++) {
            int l = A[i - 2];
            int r = min(j, B[i - 2]);
            ndp[j] += (ds[r + 1] - ds[l] + MOD) % MOD;
            ndp[j] %= MOD;
            /*for(int k = A[i - 2]; k <= min(j, B[i - 2]); k++) {
                ndp[j] += dp[k];
                ndp[j] %= MOD;
            }*/
        }

        swap(dp, ndp);
        for(int i = 0; i <= 3000; i++) {
            ds[i + 1] = ds[i] + dp[i];
        }
    }

    LL ans = 0LL;
    for(int i = A[N - 1]; i <= B[N - 1]; i++) {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
