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
    int N, D;
    cin >> N >> D;

    vector<LL> p_2(max(D, N) + 1);
    p_2[0] = 1LL;
    for(int i = 1; i <= max(D, N); i++) {
        p_2[i] = p_2[i - 1] * 2LL;
        p_2[i] %= MOD;
    }

    LL ans = 0LL;
    for(int d = 0; d < N; d++) {    // d means depth from root (calculate level by level)
        LL tot = 0LL;
        
        if(d + D < N) {
            tot += p_2[D];
            tot %= MOD;
        }
    
        // k belongs to (max(0, d + D - N), min(D, N - d))
        int l = max(0, d + D - N);
        int r = min(D, N - d);
        int cnt_k = r - l - 1;
        if(cnt_k > 0 && D > 1) {
            tot += p_2[D - 2] * cnt_k % MOD;
            tot %= MOD;
        }

        tot *= 2LL;
        tot %= MOD;

        ans += p_2[d] * tot % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
