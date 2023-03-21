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
    LL X;
    cin >> X;

    LL bal = 100LL;
    int ans = 0;
    while(bal < X) {
        bal += bal / 100LL;
        ans += 1;
    }

    cout << ans << '\n'; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
