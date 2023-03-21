#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int K, A, B;
    cin >> K >> A >> B;

    cout << (B / K >= (A + K - 1) / K ? "OK" : "NG") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
