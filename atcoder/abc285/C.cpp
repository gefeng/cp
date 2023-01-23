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
    string S;
    cin >> S;

    LL ans = 0LL;
    LL d = 1LL;
    int n = S.length();
    for(int i = n - 1; i >= 0; i--) {
        ans += d * (S[i] - 'A' + 1);
        d *= 26LL;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
