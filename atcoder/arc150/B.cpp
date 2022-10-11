#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;
const LL MAX = 45000LL;

void run_case() {
    LL A, B;
    cin >> A >> B;

    if(A == B) {
        cout << 0 << '\n';
        return;
    }

    if(A > B) {
        cout << A - B << '\n';    
        return;
    }

    LL ans = INF;
    for(LL k = A; k <= MAX; k++) {
        LL x = k - A;
        LL y = (B + k - 1LL) / k * k - B;
        if(y >= 0) {
            ans = min(ans, x + y);
        }
    }

    for(LL k = 1LL; k <= MAX; k++) {
        LL z = B <= k * A ? A : (B + k - 1LL) / k;
        LL x = z - A;
        LL y = z * k - B;
        if(x >= 0 && y >= 0) {
            ans = min(ans, x + y);
        }
    }
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
