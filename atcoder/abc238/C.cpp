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
    LL N;
    cin >> N;

    LL ans = 0LL;
    for(LL i = 1LL; i <= min(9LL, N); i++) {
        ans += i; 
    }

    for(LL i = 10LL; i <= N; i *= 10LL) {
        LL x = min(N, i * 10LL - 1LL) - i + 1LL;
    
        if(x % 2 == 0) {
            ans += ((x / 2LL) % MOD) * ((x + 1) % MOD) % MOD;
            ans %= MOD;
        } else {
            ans += ((x + 1LL) / 2LL % MOD) * (x % MOD) % MOD;
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
