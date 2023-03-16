#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int X, Y;
    cin >> X >> Y;

    if((4 * X - Y) >= 0 && (4 * X - Y) % 2 == 0 && (Y - 2 * X) >= 0 && (Y - 2 * X) % 2 == 0) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
