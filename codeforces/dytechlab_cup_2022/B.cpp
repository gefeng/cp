#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL sqrt(LL x) {
    LL lo = 1LL;
    LL hi = (LL)1e9;
    LL ans = 0LL;
    while(lo <= hi) {
        LL mid = (lo + hi) >> 1;
        LL sq_1 = mid * mid;
        LL sq_2 = (mid + 1) * (mid + 1);
        if(x >= sq_1 && x < sq_2) {
            ans = mid;
            break;
        }
        if(sq_1 < x) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

LL solve(LL max) {
    if(max == 0LL) {
        return 0LL;
    }    

    LL x = sqrt(max);
    LL res = (x - 1LL) * 3LL;
    
    for(LL i = 0LL; i < 3LL; i++) {
        if(x * (x + i) <= max) {
            res++;
        }
    }
    return res;
}

void run_case() {
    LL L, R;
    cin >> L >> R;

    LL ans = solve(R) - solve(L - 1LL);

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
