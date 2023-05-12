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

    auto is_pal = [](const std::string& S) {
        for(int l = 0, r = S.size() - 1; l < r; l += 1, r -= 1) {
            if(S[l] != S[r]) {
                return false;
            }
        } 
        return true;
    };

    std::cout << (is_pal(S) && 
            is_pal(S.substr(0, (S.size() - 1) / 2)) && 
            is_pal(S.substr((S.size() + 3) / 2 - 1, S.size() - (S.size() + 3) / 2 + 1)) ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
