#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;
    
    int l = std::min(X, Y);
    int r = std::max(X, Y);
    
    std::cout << (l <= Z && r >= Z ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
