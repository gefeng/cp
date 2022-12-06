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
    LL N;
    cin >> N;

    LL ans = 0LL;
    for(LL a = 1; a <= 5000; a++) {
        LL x = sqrt(N / a);
        for(LL b = a; b <= x; b++) {
            ans += N / (a * b) - b + 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
