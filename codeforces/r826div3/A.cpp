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

    if(S.back() == T.back()) {
        if(S.size() == T.size()) {
            std::cout << "=" << '\n';
            return;
        }
        if(S.back() == 'S') {
            std::cout << (S.size() > T.size() ? "<" : ">") << '\n';
        } else {
            std::cout << (S.size() < T.size() ? "<" : ">") << '\n';
        }
    } else {
        if((S.back() == 'S' && T.back() == 'M') || (S.back() == 'M' && T.back() == 'L') || (S.back() == 'S' && T.back() == 'L')) {
            std::cout << "<" << '\n';
        } else {
            std::cout << ">" << '\n';
        }
    }
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
