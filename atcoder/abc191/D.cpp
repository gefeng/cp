#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
using LL = long long;

const LL Z = (LL)1e4;

void run_case() {
    double X, Y, R;
    cin >> X >> Y >> R;

    auto convert = [](double x) {
        return round(x * Z);
    };
    
    LL cx = convert(X);
    LL cy = convert(Y);
    LL r = convert(R);

    auto is_ok = [&](LL x, LL y) -> bool {
        return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
    };

    auto ceil = [&](LL x) {
        if(x < 0) {
            x = -x;
            return x / Z * Z * -1LL;
        }
        return (x + Z - 1LL) / Z * Z;
    };

    auto floor = [&](LL x) {
        if(x < 0) {
            x = -x;
            return  (x + Z - 1LL) / Z * Z * -1LL;
        }
        return x / Z * Z;
    };

    /*cout << ceil(-99999) << '\n';
    cout << ceil(99999) << '\n';
    cout << floor(-99999) << '\n';
    cout << floor(99999) << '\n';*/
    
    LL ans = 0LL;
    for(LL x = ceil(cx - r); x <= floor(cx + r); x += Z) {
        LL lo = 0LL;
        LL hi = r;
        LL res = 0LL;
        while(lo <= hi) {
            LL mid = (lo + hi) >> 1LL;
            
            if(is_ok(x, cy + mid)) {
                res = mid;
                lo = mid + 1LL;
            } else {
                hi = mid - 1LL;
            }
        }

        //LL l = cy - res;
        //LL r = cy + res;
        LL l = ceil(cy - res);
        LL r = floor(cy + res);
        ans += (r - l) / Z + 1LL;
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
