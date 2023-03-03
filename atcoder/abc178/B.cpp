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
    LL A, B, C, D;
    cin >> A >> B >> C >> D;

    if(B < 0 && C > 0) {
        cout << B * C << '\n';
        return;
    }

    if(D < 0 && A > 0) {
        cout << A * D << '\n';
        return;
    }

    cout << max(B * D, A * C) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
