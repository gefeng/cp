#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int x = std::stoi(S.substr(3, 3));
    if(x >= 350 || x == 316 || x == 0) {
        std::cout << "No" << '\n';
    } else {
        std::cout << "Yes" << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
