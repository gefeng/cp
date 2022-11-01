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
    LL A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    LL x = (A % MOD) * (B % MOD) % MOD;
    x *= C % MOD;
    x %= MOD;

    LL y = (D % MOD) * (E % MOD) % MOD;
    y *= F % MOD;
    y %= MOD;

    LL ans = (x - y + MOD) % MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
