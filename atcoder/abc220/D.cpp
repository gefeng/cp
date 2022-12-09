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
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<LL> dp(10, 0LL);
    dp[(A[0] + A[1]) % 10] += 1LL;
    dp[(A[0] * A[1]) % 10] += 1LL;
    
    for(int i = 2; i < N; i++) {
        vector<LL> ndp(10, 0LL);

        for(int j = 0; j < 10; j++) {
            ndp[(j + A[i]) % 10] += dp[j];
            ndp[(j + A[i]) % 10] %= MOD;
            ndp[(j * A[i]) % 10] += dp[j];
            ndp[(j * A[i]) % 10] %= MOD;
        }

        swap(dp, ndp);
    }

    for(int i = 0; i < 10; i++) {
        cout << dp[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
