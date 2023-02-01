#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    array<int, 3> A{0};
    for(int i = 0; i < 3; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    cout << (A[1] - A[0] == A[2] - A[1] ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
