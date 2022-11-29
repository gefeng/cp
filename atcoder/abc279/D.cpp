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

double f(double A, double B, double t) {
    return B * t + A / sqrt(t + 1.0);
}

void run_case() {
    LL A, B;
    cin >> A >> B;

    LL lo = 0LL;
    LL hi = (LL)1e18;

    while(hi - lo > 2LL) {
        LL m_1 = lo + (hi - lo) / 3LL;
        LL m_2 = hi - (hi - lo) / 3LL;

        if(f(A, B, m_1) < f(A, B, m_2)) {
            hi = m_2;
        } else {
            lo = m_1;
        }
    }

    double ans = 1e18;
    for(LL i = lo; i <= hi; i += 1LL) {
        ans = min(ans, f(A, B, i));
    } 
    
    cout << setprecision(19) << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
