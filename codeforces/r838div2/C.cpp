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

LL q_pow(LL x, LL y) {
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
    cin >> N;

    string S;
    cin >> S;

    LL ans = 1LL;
    LL cnt = 1LL;
    for(int i = 1; i < N; i++) {
        if(S[i] == S[i - 1]) {
            cnt *= 2LL; 
            cnt %= MOD;
        } else {
            cnt = 1LL;
        }
        ans += cnt;
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
