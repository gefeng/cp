#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    LL X;
    cin >> X;

    if(X >= 0) {
        cout << X / 10LL << '\n';
    } else {
        cout << (-X + 10LL - 1LL) / 10LL * -1LL << '\n';;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
