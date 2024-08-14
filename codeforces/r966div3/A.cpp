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
    if(n < 3) {
        std::cout << "No" << '\n';
        return;
    }

    if(S.substr(0, 2) != "10") {
        std::cout << "No" << '\n';
        return;
    }

    if(S[2] == '0') {
        std::cout << "No" << '\n';
        return;
    }

    if(S[2] == '1' && n == 3) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
