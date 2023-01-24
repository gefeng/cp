#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int A, B, C;
    cin >> A >> B >> C;

    if(A != B && B != C && A != C) {
        cout << 0 << '\n';
    } else {
        if(A == B) {
            cout << C << '\n';
        } else if(A == C) {
            cout << B << '\n';
        } else {
            cout << A << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
