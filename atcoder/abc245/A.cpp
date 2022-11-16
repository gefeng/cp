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

    int x = A * 60 + B;
    int y = C * 60 + D;

    if(x <= y) {
        cout << "Takahashi" << '\n';
    } else {
        cout << "Aoki" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
