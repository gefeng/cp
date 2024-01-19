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

    std::sort(S.begin(), S.end());
    std::sort(T.begin(), T.end());

    auto is_side = [](std::string& s) {
        return s == "AB" || s == "BC" || s == "CD" || s == "DE" || s == "AE";
    };
    
    bool a = is_side(S);
    bool b = is_side(T);

    if((a && b) || (!a && !b)) {
        std::cout << "Yes" << '\n';
        return;
    }
    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
