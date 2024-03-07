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

    if(S[0] >= 'a' && S[0] <= 'z') {
        std::cout << "No" << '\n';
        return;
    }

    int n = S.size();
    for(int i = 1; i < n; i++) {
        if(S[i] >= 'A' && S[i] <= 'Z') {
            std::cout << "No" << '\n';
            return;
        } 
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
