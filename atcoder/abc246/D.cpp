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

void run_case() {
    LL N;
    cin >> N;

    LL max_v = 0LL;
    while(max_v * max_v * max_v <= N) {
        max_v += 1LL;
    }

    auto f = [](LL a, LL b) {
        return a * a * a + a * a * b + a * b * b + b * b * b;
    };

    LL ans = INF;
    for(LL a = 0LL; a <= max_v; a += 1LL) {
        LL lo = 0LL;
        LL hi = max_v; 
        LL b = 0LL;
        while(lo <= hi) {
            LL mid = (lo + hi) >> 1LL;
            
            if(f(a, mid) >= N) {
                b = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        ans = min(ans, f(a, b));
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
