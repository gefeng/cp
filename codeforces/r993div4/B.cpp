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
    
    std::reverse(S.begin(), S.end());

    int n = S.size();    
    for(int i = 0; i < n; i++) {
        if(S[i] == 'p') {
            S[i] = 'q';
        } else if(S[i] == 'q') {
            S[i] = 'p';
        }
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
