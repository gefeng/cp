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

    LL lo = 1LL;
    LL hi = (LL)1e10;
    LL ans = 1LL;
    while(lo <= hi) {
        LL mid = (lo + hi) >> 1;
        LL tot = mid - mid / N;
        
        if(tot >= K) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
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
