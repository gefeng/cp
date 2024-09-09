#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int L, R;
    std::cin >> L >> R;
    
    if(L == R) {
        std::cout << "Invalid" << '\n';
        return;
    }

    std::cout << (L == 1 ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
