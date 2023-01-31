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

    if(X == Y) {
        cout << X << '\n';
    } else {
        cout << 3 - X - Y << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
