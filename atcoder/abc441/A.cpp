#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int P, Q, X, Y;
    std::cin >> P >> Q >> X >> Y;

    std::cout << (X >= P && X < P + 100 && Y >= Q && Y < Q + 100 ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
