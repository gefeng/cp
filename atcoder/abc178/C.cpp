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

void run_case() {
    int N;
    cin >> N;
    
    if(N == 1) {
        cout << 0 << '\n';
        return;
    }

    LL ans = 1LL;
    for(int i = 0; i < N; i++) {
        ans *= 10LL;
        ans %= MOD;
    }

    LL no_0 = 1LL;
    for(int i = 0; i < N; i++) {
        no_0 *= 9LL;
        no_0 %= MOD;
    }

    LL no_9 = 1LL;
    for(int i = 0; i < N; i++) {
        no_9 *= 9LL;
        no_9 %= MOD;
    }

    LL no_09 = 1LL;
    for(int i = 0; i < N; i++) {
        no_09 *= 8LL;
        no_09 %= MOD;
    }

    ans = (ans - no_0 + MOD) % MOD;
    ans = (ans - no_9 + MOD) % MOD;
    ans = (ans + no_09) % MOD;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
