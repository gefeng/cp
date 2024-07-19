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
    std::string T;
    std::cin >> S >> T;

    bool has_one = false;
    for(int i = 0; i < N; i++) {
        if(S[i] != T[i] && S[i] == '0') {
            if(has_one) {
                S[i] = '1';
            } else {
                std::cout << "No" << '\n';
                return;
            }
        }
        
        if(S[i] == '1') {
            has_one = true;
        }
    }

    // has_one = false;
    // for(int i = 0; i < N; i++) {
    //     if(S[i] != T[i]) {
    //         if(!has_one) {
    //             std::cout << "No" << '\n';
    //             return;
    //         }
    //     }
    //
    //     if(S[i] == '1') {
    //         has_one = true;
    //     }
    // }

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
