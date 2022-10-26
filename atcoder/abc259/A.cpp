#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;

    if(M <= X) {
        cout << T - D * (X - M) << '\n';
    } else {
        cout << T << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
