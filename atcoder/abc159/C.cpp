#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

void run_case() {
    int L;
    std::cin >> L;

    double a = (double)L / 3;
    double v = a * a * a;
   
    std::cout << std::setprecision(20) << v << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
