#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL q_pow(LL x, LL y, LL MOD) {
    LL res = 1LL;
    while(y) {
        if(y & 1) {
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
    LL MOD;
    cin >> N >> MOD;

    vector<LL> fact(N + 1, 0LL);
    fact[0] = 1LL;
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    vector<LL> invf(N + 1, 0LL);
    invf[0] = 1LL;
    for(int i = 1; i <= N; i++) {
        invf[i] = q_pow(fact[i], MOD - 2LL, MOD);
    }

    /*vector<vector<LL>> comb(N + 1, vector<LL>(N + 1, 0LL));
    comb[0][0] = 1LL;
    for(int i = 1; i <= N; i++) {
        comb[i][0] = 1LL;
        comb[i][i] = 1LL;
        for(int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }*/

    LL ans = 0LL;

    // fix one of the pivot 0, and enumerate the other pivot x.
    for(int x = 0; x <= (N + 1) / 2 - 1; x++) {
        LL sum = 0LL;
        LL last = N / 2 + x - (N + 1) / 2 + 1;
        LL optional = max(0LL, 1LL * x - 1);
        for(int y = 0; y <= optional; y++) {
            LL bion = (fact[optional] * invf[y] % MOD) * invf[optional - y] % MOD;
            sum += (bion * fact[N - x - 1 + y - 1] % MOD) * last % MOD;
            sum %= MOD;
        } 
        ans += sum;
        ans %= MOD;
    }

    // enumerate firt pivot from 0 to N - 1
    ans *= N;
    ans %= MOD;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
