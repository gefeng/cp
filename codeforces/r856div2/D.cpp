#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;
using LL = long long;

const int MAX = (int)1e6;
const LL MOD = 998244353LL;

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y & 1LL) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1LL;
    }
    return res;
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(2 * N);
    for(int i = 0; i < N * 2; i++) {
        cin >> A[i];
    }

    vector<bool> is_p(MAX + 1, true);
    is_p[1] = false;
    for(int i = 2; i <= MAX; i++) {
        if(is_p[i]) {
            for(int j = i + i; j <= MAX; j += i) {
                is_p[j] = false;
            }
        }
    }

    map<int, int> fm1;
    map<int, int> fm2;
    for(int x : A) {
        if(is_p[x]) {
            fm1[x] += 1;
        } else {
            fm2[x] += 1;
        }
    }

    vector<int> p;
    vector<int> np;
    for(auto [k, v] : fm1) {
        p.push_back(v);
    }

    for(auto [k, v] : fm2) {
        np.push_back(v);
    }

    int m = p.size();
    if(m < N) {
        cout << 0 << '\n';
        return;
    }

    vector<LL> fact(2 * N + 1, 1LL);
    vector<LL> invf(2 * N + 1, 1LL);
    for(int i = 1; i <= 2 * N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    for(int i = 1; i <= 2 * N; i++) {
        invf[i] = q_pow(fact[i], MOD - 2LL);
    }

    vector<vector<LL>> dp(m + 1, vector<LL>(N + 1, 0LL));
    dp[0][0] = 1LL;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= min(i, N); j++) {
            if(j < i) {
                dp[i][j] += dp[i - 1][j] * invf[p[i - 1]] % MOD;
                dp[i][j] %= MOD;
            }
            if(j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * invf[p[i - 1] - 1] % MOD;
                dp[i][j] %= MOD;
            }
        }
    } 

    LL x = fact[N];
    if(np.size()) {
        for(int y : np) {
            x *= invf[y]; 
            x %= MOD;
        }
    }
    
    LL ans = dp[m][N] * x % MOD;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
