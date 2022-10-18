#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)998244353;

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y & 1LL) {
            res *= x;
            res %= MOD;
        }
        y /= 2LL;
        x *= x;
        x %= MOD;
    }

    return res;
}

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> P(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    LL tot = 1LL;
    for(int i = 0; i < N; i++) {
        tot *= M; 
        tot %= MOD;
    } 

    int cnt = 0;
    vector<bool> seen(N, false);
    for(int i = 0; i < N; i++) {
        if(seen[i]) {
            continue;
        } 

        int cur = i;
        int head = i;
        do {
            seen[cur] = true;
            cur = P[cur];
        } while(cur != head);
        
        cnt++;
    }

    LL cnt_same = 1LL;
    for(int i = 0; i < cnt; i++) {
        cnt_same *= M;
        cnt_same %= MOD;
    }

    LL ans = ((tot - cnt_same + MOD) % MOD);
    ans *= q_pow(2LL, MOD - 2LL);
    ans %= MOD;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
