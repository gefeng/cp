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
    LL X, K, D;
    cin >> X >> K >> D;

    LL dist = abs(X);
    
    LL steps = dist / D;
    if(steps >= K) {
        cout << dist - (K * D) << '\n';
    } else {
        LL left = K - steps;

        if(left % 2LL == 0LL) {
            cout << dist - (steps * D) << '\n';
        } else {
            cout << (steps + 1LL) * D - dist << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
