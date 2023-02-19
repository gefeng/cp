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

LL lcm(LL a, LL b) {
    return a * b / gcd(a, b);
}

void run_case() {
    LL N, D, K;
    cin >> N >> D >> K;

    LL W = lcm(N, D) / D;

    LL ans = (K - 1) / W + (((K - 1) % W) * D % N);
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
