#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int R, X;
    std::cin >> R >> X;

    if(X == 1) {
        std::cout << (R >= 1600 && R <= 2999 ? "Yes" : "No") << '\n';
    } else {
        std::cout << (R >= 1200 && R <= 2399 ? "Yes" : "No") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
