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
    LL L, R;
    cin >> L >> R;

    // if g >= L
    LL ans = max(0LL, R / 2LL - L + 1LL);

    // if g < L
    for(LL g = 1LL; g < L; ) {
        LL x = (L + g - 1LL) / g;

        LL l = g;
        LL r = (L - 1LL) / ((L - 1LL) / l);
        ans += max(0LL, min(R / (x + 1LL), r) - l + 1LL);
        g = r + 1LL;
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
