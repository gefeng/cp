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
    LL A, B, N;
    cin >> A >> B >> N;
    
    auto f = [&](LL x) {
        return (A * x) / B - A * (x / B);
    };

    if(N < B) {
        cout << f(N) << '\n';
    } else if(N == B) {
        cout << f(B - 1) << '\n';
    } else {
        cout << f((N + 1) / B * B - 1) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
