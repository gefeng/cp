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
    int N;
    cin >> N;

    LL lo = 0LL;
    LL hi = (LL)1e9;
    LL ans = 0LL;
    while(lo <= hi) {
        LL mid = (lo + hi) >> 1;

        LL l1 = 1LL;
        LL l2 = l1 + mid;
        LL l3 = l2 + mid;
        if(l1 + l2 + l3 + 3LL <= N) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
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
