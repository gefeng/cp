#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = 998244353;

void run_case() {
    int N;
    cin >> N;

    array<array<LL, 61>, 61> comb{{{0}}};
    comb[0][0] = 1LL;
    for(int i = 1; i <= 60; i++) {
        comb[i][0] = 1LL;
        comb[i][i] = 1LL;

        for(int j = 1; j < i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            comb[i][j] %= MOD;
        }
    }
   
    vector<LL> dp_a(N + 1, 0LL);
    vector<LL> dp_b(N + 1, 0LL);
    vector<LL> dp_c(N + 1, 0LL);
    dp_a[2] = 1LL; 
    dp_b[2] = 0LL;
    dp_c[2] = 1LL;

    for(int i = 4; i <= N; i += 2) {
        dp_a[i] = comb[i - 1][i / 2 - 1];
        dp_a[i] += dp_b[i - 2];
        dp_a[i] %= MOD;

        dp_b[i] = comb[i - 2][i / 2 - 2];
        dp_b[i] += dp_a[i - 2];
        dp_b[i] %= MOD;

        dp_c[i] += comb[i][i / 2] - ((dp_a[i] + dp_b[i]) % MOD) + MOD;
        dp_c[i] %= MOD;
    }

    cout << dp_a[N] << ' ' << dp_b[N] << ' ' << dp_c[N] << '\n';
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
