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

    auto f = [](int a) {
        int sum = 0;
        while(a) {
            sum += a % 10;
            a /= 10;
        }
        return sum;
    };

    cout << max(f(A), f(B)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
