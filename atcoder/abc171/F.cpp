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
const int MAX = 2000000;

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y & 1LL) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int K;
    cin >> K;

    string S;
    cin >> S;

    int n = S.size();

    vector<LL> fact(MAX + 1, 1LL);
    vector<LL> invf(MAX + 1, 1LL);
    vector<LL> p_25(MAX + 1, 1LL);
    vector<LL> p_26(MAX + 1, 1LL);
    for(int i = 2; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    for(int i = 2; i <= MAX; i++) {
        invf[i] = q_pow(fact[i], MOD - 2LL);
    }
    
    for(int i = 1; i <= MAX; i++) {
        p_25[i] = p_25[i - 1] * 25LL % MOD;
    }

    for(int i = 1; i <= MAX; i++) {
        p_26[i] = p_26[i - 1] * 26LL % MOD; 
    } 

    LL ans = 0LL;
    for(int i = n - 1; i < n + K; i++) {
        LL x = (((fact[i] * invf[n - 1] % MOD) * invf[i - n + 1] % MOD) * p_25[i + 1 - n] % MOD) * p_26[n + K - i - 1] % MOD;
        ans += x;
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
