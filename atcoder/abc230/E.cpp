#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

void run_case() {
    LL N;
    cin >> N;

    LL ans = 0LL;
    for(LL i = 1LL; i * i <= N; i++) {
        ans += N / i;
    }

    // math:
    // for i > sqrt(N), floor(N / i) < sqrt(N);
    // let k = floot(N / i) we can enumerate k and count each k's occurence.
    // for a specific k, we can prove that i belongs to range (N / (k + 1), N / k]
    LL root = (LL)sqrt(N);
    for(LL k = 1LL; k * k < N; k++) {
        LL l = max(root, N / (k + 1LL));
        LL r = max(root, N / k);

        ans += k * (r - l); 
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
