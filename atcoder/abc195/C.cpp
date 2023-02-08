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
    for(LL i = 1LL, j = 0; i <= N; i *= 1000LL, j += 1) {
        if(i * 1000LL <= N) {
            ans += (i * 1000LL - i) * j;
        } else {
            ans += (N - i + 1) * j;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
