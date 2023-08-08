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
    int c = 0;
    int j = -1;
    std::string ans = "";
    for(int i = n - 1; i >= 0; i--) {
        int d = S[i] - '0' + c;
        if(d > 4) {
            S[i] = '0';
            c = 1;
            j = i;
        } else {
            S[i] = (char)(d + '0');
            c = 0;
        }
    }

    for(int i = j; i < S.size(); i++) {
        S[i] = '0';
    }

    if(c) {
        S = "1" + S;
    }

    std::cout << S << '\n';
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
