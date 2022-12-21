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

    if(N == 1) {
        cout << 0 << '\n';
        return;
    }

    int k = 1;
    LL x = 2LL;
    while(x <= N) {
        x *= 2LL;
        k += 1;
    }

    cout << k - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
