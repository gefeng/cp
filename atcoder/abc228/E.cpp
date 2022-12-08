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

LL q_pow(LL x, LL y, LL p) {
    LL res = 1LL;
    x %= p;
    while(y) {
        if(y & 1LL) {
            res *= x;
            res %= p;
        }
        x *= x;
        x %= p;
        y >>= 1LL;
    }
    return res;
}

void run_case() {
    LL N, K, M;
    cin >> N >> K >> M;

    LL x = q_pow(K, N, MOD - 1LL);
    LL ans = q_pow(M, x, MOD);
    if(M % MOD == 0) {
        ans = 0LL;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
