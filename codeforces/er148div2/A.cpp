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
    bool same = true;
    for(int i = 1; i < n; i++) {
        if(S[i] != S[0]) {
            same = false;
            break;
        }
    }

    if(same) {
        std::cout << "NO" << '\n';
        return;
    }

    if(n % 2 == 1) {
        same = true;
        for(int i = 1; i < n; i++) {
            if(i != n / 2 && S[i] != S[0]) {
                same = false;
                break;
            }
        } 

        if(same) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
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
