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

void run_case() {
    int L, R;
    cin >> L >> R;

    int max_sz = 1;
    int x = L;
    while(x * 2 <= R) {
        x *= 2;
        max_sz += 1;
    }

    if(max_sz == 1) {
        cout << max_sz << ' ' << R - L + 1 << '\n';
        return;
    }
     
    int p_2 = 1;
    int p_3 = 0;
    for(int i = 0; i < max_sz - 1; i++) {
        p_2 *= 2;
    }
     
    p_3 = p_2 / 2 * 3;

    LL ans = R / p_2 - L + 1;
    ans += max(0, R / p_3 - L + 1) * (max_sz - 1) % MOD;

    cout << max_sz << ' ' << ans << '\n';
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
