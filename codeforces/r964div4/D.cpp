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

    int n = S.size();
    int m = T.size();
    
    int i = 0;
    int j = 0;
    for(; i < n && j < m; i++) {
        if(S[i] == '?' || S[i] == T[j]) {
            if(S[i] == '?') {
                S[i] = T[j];
            }
            j += 1;
        }
    }

    std::cout << (j == m ? "Yes" : "No") << '\n';

    if(j == m) {
        for(i = 0; i < n; i++) {
            if(S[i] == '?') {
                S[i] = 'a';
            }
        }
        std::cout << S << '\n';
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
