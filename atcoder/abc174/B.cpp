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
    int N, D;
    cin >> N >> D;

    auto f = [&](int x, int y) {
        return 1LL * x * x + 1LL * y * y <= 1LL * D * D; 
    };

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;

        if(f(X, Y)) {
            ans += 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
