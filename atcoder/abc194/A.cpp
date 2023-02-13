#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int A, B;
    cin >> A >> B;

    int C = A + B;

    if(C >= 15 && B >= 8) {
        cout << 1 << '\n';
    } else if(C >= 10 && B >= 3) {
        cout << 2 << '\n';
    } else if(C >= 3) {
        cout << 3 << '\n';
    } else {
        cout << 4 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
