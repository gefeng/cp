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
    LL A, B;
    cin >> A >> B;

    while(A && B) {
        if((A % 10) + (B % 10) > 9) {
            cout << "Hard" << '\n';
            return;
        }
        A /= 10LL;
        B /= 10LL;
    }

    cout << "Easy" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
