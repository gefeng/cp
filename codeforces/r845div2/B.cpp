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

    LL tot = 1LL;
    for(int i = 1; i <= N; i++) {
        tot *= i; 
        tot %= MOD;
    }

    LL ans = 0LL;
    for(int i = 1; i <= N; i++) {
        ans += tot * (2LL * i - 2LL) % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
