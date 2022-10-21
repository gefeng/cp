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

LL gcd(LL a, LL b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    LL M;
    cin >> N >> M;

    LL tot = 1LL;
    vector<LL> p(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        tot *= (M % MOD);
        tot %= MOD;
        p[i] = tot;
    }

    LL cnt_one = M % MOD;
    LL g = 1LL;
    for(int i = 2; i <= N; i++) {
        if(g <= M && gcd(g, i) == 1LL) {
            g *= i;
        } 

        LL x = M / g;
        
        if(x == 0) {
            break;
        }
        cnt_one *= x % MOD;
        cnt_one %= MOD;
        p[i] -= cnt_one;
        p[i] += MOD;
        p[i] %= MOD;
    }

    LL ans = 0LL;
    for(int i = 2; i <= N; i++) {
        ans += p[i];
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
