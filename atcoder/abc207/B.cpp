#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if(D * C - B <= 0) {
        cout << -1 << '\n';
    } else {
        cout << (A + D * C - B - 1) / (D * C - B) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
