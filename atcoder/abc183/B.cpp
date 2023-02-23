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
    double SX, SY, GX, GY;
    cin >> SX >> SY >> GX >> GY;

    cout << setprecision(20) << (GY * SX + SY * GX) / (GY + SY) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
