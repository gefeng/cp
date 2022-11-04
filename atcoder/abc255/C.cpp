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
    LL X, A, D, N;
    cin >> X >> A >> D >> N;

    if(D == 0) {
        cout << abs(X - A) << '\n';
        return;
    }

    LL ans = (LL)2e18;

    ans = min(abs(X - A), abs(X - A - D * (N - 1LL)));

    LL lb = (X - A) / D;
    LL ub = (X - A + D - 1LL) / D;
    if(lb >= 0 && lb < N) {
        ans = min(ans, abs(lb * D + A - X));
    }
    if(ub >= 0 && ub < N) {
        ans = min(ans, abs(ub * D + A - X));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
