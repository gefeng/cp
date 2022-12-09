#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int X;
    cin >> X;

    if(X >= 90) {
        cout << "expert" << '\n';
        return;
    }

    if(X >= 70 && X < 90) {
        cout << 90 - X << '\n';
    } else if(X >= 40 && X < 70) {
        cout << 70 - X << '\n';
    } else {
        cout << 40 - X << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
