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
    int N, K;
    cin >> N >> K;

    LL ans = N;
    for(int i = 0; i < K; i++) {
        if(ans % 200LL == 0LL) {
            ans /= 200LL;
        } else {
            ans *= 1000LL;
            ans += 200LL;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
