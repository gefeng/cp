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
    string X;
    LL M;

    cin >> X >> M;

    if(X.size() == 1) {
        LL x = X[0] - '0';
        if(x <= M) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        return;
    }

    int d = 0;
    int n = X.size();
    for(char c : X) {
        d = max(d, c - '0');
    }

        
    LL ans = 0LL;
    LL lo = d + 1LL;
    LL hi = M;
    while(lo <= hi) {
        LL mid = (lo + hi) >> 1LL;

        bool ok = true;
        LL cur = 0LL;
        for(int i = 0; i < n; i++) {
            if(cur > M / mid) {
                // check overflow: cur * mid <= M -> cur <= M / mid
                ok = false;
                break;
            }
            cur *= mid;
            cur += X[i] - '0';
        }

        ok = ok && cur <= M;
        
        if(ok) {
            ans = mid - d;
            lo = mid + 1LL;
        } else {
            hi = mid - 1LL;
        }
    }
    
    cout << ans << '\n'; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
