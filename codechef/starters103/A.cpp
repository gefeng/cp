#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    auto modular = [](int n, std::string& s) {
        int rem = 0;
        for(int i = 0; i < n; i++) {
            rem = rem * 10 + s[i] - '0'; 
            rem %= 8;
        }
        return rem;
    };

    if(modular(N, S) == 0) {
        std::cout << S << '\n';
        return;
    }

    for(char c = N == 1 ? '1' : '0'; c <= '9'; c++) {
        S[N - 1] = c;
        if(modular(N, S) == 0) {
            std::cout << S << '\n';
            return;
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
