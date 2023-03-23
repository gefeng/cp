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
    LL N;
    cin >> N;

    LL lo = 0LL;
    LL hi = (LL)1e9;
    LL k1 = 0LL;
    while(lo <= hi) {
        LL mid = (lo + hi) >> 1;
        
        if(mid * (mid + 1LL) >= (N - 1LL + 3LL) / 4LL) {
            k1 = mid;
            hi = mid - 1LL;
        } else { 
            lo = mid + 1LL;
        }
    }

    lo = 0LL;
    hi = (LL)1e9;
    LL k2 = 0LL;
    while(lo <= hi) {
        LL mid = (lo + hi) >> 1;
        
        if(mid * mid >= (N + 3LL) / 4LL) {
            k2 = mid;
            hi = mid - 1LL;
        } else { 
            lo = mid + 1LL;
        }
    }

    cout << min(2LL * k1, 2LL * k2 - 1LL) << '\n';
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
