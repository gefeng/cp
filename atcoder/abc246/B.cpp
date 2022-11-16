#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void run_case() {
    int A, B;
    cin >> A >> B;

    double d = sqrt(A * A + B * B);
    double x = (double)A / d;
    double y = (double)B / d;

    cout << setprecision(19) << x << ' ' << y << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
