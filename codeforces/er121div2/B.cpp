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
    
    for(int i = 0; i < n - 1; i++) {
        int a = S[i] - '0';
        int b = S[i + 1] - '0';
        int x = std::stoi(S.substr(i, 2));
        if(a + b > 9 && a + b > x) {
            std::string s = std::to_string(a + b);
            S[i] = s[0];
            S[i + 1] = s[1];
            std::cout << S << '\n';
            return;
        } 
    }

    for(int i = n - 1; i > 0; i--) {
        int a = S[i - 1] - '0';
        int b = S[i] - '0';
        if(a + b > 9) {
            std::string s = std::to_string(a + b);
            S[i - 1] = s[0];
            S[i] = s[1];
            std::cout << S << '\n';
            return;
        }
    }

    S[1] = char(S[0] - '0' + S[1] - '0' + '0');
    std::cout << S.substr(1, n - 1) << '\n';
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
