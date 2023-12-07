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

    for(int i = 1; i <= 8; i++) {
        if(i != S[1] - '0') {
            std::string s(1, S[0]);
            std::cout << s << i << '\n';
        }
    }

    for(char c = 'a'; c <= 'h'; c++) {
        if(c != S[0]) {
            std::string s(1, c);
            std::cout << s << S[1] << '\n';
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
