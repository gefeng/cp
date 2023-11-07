#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y;
    std::cin >> X >> Y;

    if(X <= Y) {
        std::cout << (Y - X <= 2 ? "Yes" : "No") << '\n';
    } else {
        std::cout << (X - Y <= 3 ? "Yes" : "No") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
