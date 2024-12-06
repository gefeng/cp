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
        int max_d = -1;
        int max_p = -1;
        for(int j = 0; j < 10; j++) {
            if(i + j >= n) {
                break;
            }
            int c = S[i + j] - '0';
            if(c - j >= 0 && c - j > max_d) {
                max_d = c - j;
                max_p = i + j;
            }
        } 
        
        for(int j = max_p - 1; j >= i; j--) {
            std::swap(S[j], S[j + 1]);
        }
        
        S[i] = char(max_d + '0');
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
