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
    bool inc = true;
    for(int i = 0; i < n - 1; i++) {
        if(S[i + 1] < S[i]) {
            inc = false;
            break;
        }
    }

    if(inc) {
        std::cout << "Yes" << '\n';
        return;
    }
    
    bool one_one = false;
    for(int i = 0; i < n; i++) {
        if(i && S[i] == '1' && S[i - 1] == '1') {
            one_one = true;
        } 
        
        if(i && S[i] == '0' && S[i - 1] == '0' && one_one) {
            std::cout << "No" << '\n';
            return;
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
