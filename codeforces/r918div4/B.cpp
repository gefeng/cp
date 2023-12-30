#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<std::string> A(3);
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < 3; i++) {
        std::array<int, 3> s = {};
        bool found = false;
        for(int j = 0; j < 3; j++) {
            if(A[i][j] == '?') {
                found = true; 
            } else {
                s[A[i][j] - 'A'] = 1;
            }
        }

        if(found) {
            for(int k = 0; k < 3; k++) {
                if(!s[k]) {
                    std::cout << (char)('A' + k) << '\n';
                    return;
                }
            }
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
