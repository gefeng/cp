#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

const int MAX = (int)4e5 + 10;
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
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    set<int> s;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        s.insert(A[i]);
    }

    vector<LL> fact(MAX, 1LL);
    vector<LL> invf(MAX, 1LL);
    for(int i = 2; i < MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD; 
    }

    for(int i = 2; i < MAX; i++) {
        invf[i] = q_pow(fact[i], MOD - 2LL);
    }

    LL ans = 0LL;
    int missing = 0;
    for(int mex = 0; mex <= N + K; mex += 1) {
        if(K - missing > 0) {
            ans += (fact[K - missing - 1 + mex] * invf[mex] % MOD) * invf[K - missing - 1] % MOD;
            ans %= MOD;
        }
        if(s.find(mex) == s.end()) {
            missing += 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
