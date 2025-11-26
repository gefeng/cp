#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y, Z;
    std::cin >> X >> Y >> Z;

    // a + x = z * (b + x)
    // a + x = zb + zx;
    // a - zb = zx - x;
    // x(z - 1) = a - zb

    std::cout << (X >= Y * Z && (X - Z * Y) % (Z - 1) == 0 ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
