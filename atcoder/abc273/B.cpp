#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    LL N, K;
    cin >> N >> K;

    LL d = 10LL;
    LL ans = N;
    for(LL i = 1LL; i <= K; i++) {
        LL x = ans / d;
        LL y = (ans + d - 1) / d;

        ans = abs(x * d - ans) < abs(y * d - ans) ? x * d : y * d;
        d *= 10LL;        
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
