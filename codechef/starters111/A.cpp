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

    std::string t = "CODETOWN";
    std::string v = "AEIOU";

    for(int i = 0; i < S.size(); i++) {
        if(S[i] == t[i]) {
            continue;
        }
        if(v.find(S[i]) == std::string::npos) {
            if(v.find(t[i]) != std::string::npos) {
                std::cout << "No" << '\n';
                return;
            }
        } else {
            if(v.find(t[i]) == std::string::npos) {
                std::cout << "No" << '\n';
                return;
            }
        }
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
