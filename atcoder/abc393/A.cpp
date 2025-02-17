#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S, T;
    std::cin >> S >> T;
    
    if(S != T) {
        std::cout << (S == "sick" ? 2 : 3) << '\n';
        return;
    }

    if(S == "sick") {
        std::cout << 1 << '\n';
    } else {
        std::cout << 4 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
