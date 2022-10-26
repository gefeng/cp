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
    int A, B, D;
    cin >> A >> B >> D;
    
    if(A == 0 && B == 0) {
        cout << 0 << ' ' << 0 << '\n';
        return;
    }

    double theta = atan2(B, A);
    double delta = M_PI / 180 * D;
    double r = sqrt(A * A + B * B);

    cout << setprecision(19) << r * cos(theta + delta) << ' ' << r * sin(theta + delta) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
