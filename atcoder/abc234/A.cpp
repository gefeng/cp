#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int f(int x) {
    return x * x + 2 * x + 3;
}

void run_case() {
    int X;
    cin >> X;

    cout << f(f(f(X) + X) + f(f(X))) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
