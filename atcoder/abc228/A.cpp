#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int S, T, X;
    cin >> S >> T >> X;

    S = S * 60;
    T = T * 60;
    X = (X * 60 + 30) % (24 * 60);

    if(S > T) {
        cout << (X >= S || X <= T ? "Yes" : "No") << '\n';
    } else {
        cout << (X >= S && X <= T ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
