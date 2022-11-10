#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int A, B, C, D, E, F, X;
    cin >> A >> B >> C >> D >> E >> F >> X;

    int x = X / (A + C) * B * A;
    x += min(X % (A + C), A) * B;

    int y = X / (D + F) * E * D;
    y += min(X % (D + F), D) * E;

    if(x == y) {
        cout << "Draw" << '\n';
    } else {
        cout << (x > y ? "Takahashi" : "Aoki") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
