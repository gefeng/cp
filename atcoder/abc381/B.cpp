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

    int n = S.size();
    if(n % 2 == 1) {
        std::cout << "No" << '\n';
        return;
    }

    std::array<int, 26> seen = {};
    for(int i = 0; i < n; i += 2) {
        if(S[i] != S[i + 1] || seen[S[i] - 'a']) {
            std::cout << "No" << '\n';
            return;
        } 
        seen[S[i] - 'a'] = 1;
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
