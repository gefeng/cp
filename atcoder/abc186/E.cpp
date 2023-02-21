#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL gcd(LL a, LL b) {
    if(a == 0LL) {
        return b;
    }
    return gcd(b % a, a);
}

LL extended_euclidean(LL a, LL b, LL& x, LL& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL x1, y1;
    LL d = extended_euclidean(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

LL inv_mod(LL a, LL MOD) {
    LL x, y;
    LL g = extended_euclidean(a, MOD, x, y);
    x = (x % MOD + MOD) % MOD;
    return x;
}

void run_case() {
    LL N, S, K;
    cin >> N >> S >> K;
    
    LL g = gcd(N, K);
    if(S % g != 0) {
        cout << -1 << '\n';
        return;
    }
    
    N /= g;
    K /= g;
    S /= g;

    LL ans = ((N - S) % N) * inv_mod(K, N) % N;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
