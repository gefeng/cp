#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

bool stack(LL X, LL Y, LL A, LL B, LL C) {
    return (A + X - 1LL) / X + (B + X - 1LL) / X + (C + X - 1LL) / X <= Y;
}

bool split(LL X, LL Y, LL A, LL B, LL C) {
    bool case1 = false;
    bool case2 = false;
    bool case3 = false;

    LL x = X - (A + Y - 1LL) / Y;
    case1 = x > 0 && (B + x - 1LL) / x + (C + x - 1LL) / x <= Y;

    x = X - (B + Y - 1LL) / Y;
    case2 = x > 0 && (A + x - 1LL) / x + (C + x - 1LL) / x <= Y;

    x = X - (C + Y - 1LL) / Y;
    case3 = x > 0 && (A + x - 1LL) / x + (B + x - 1LL) / x <= Y;

    return case1 || case2 || case3;
}
void run_case() {
    LL X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    if(stack(X, Y, A, B, C) || stack(Y, X, A, B, C)) {
        cout << "Yes" << '\n';
        return;
    }

    if(split(X, Y, A, B, C) || split(Y, X, A, B, C)) {
        cout << "Yes" << '\n';
        return;
    }

    cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
