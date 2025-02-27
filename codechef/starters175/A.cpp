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
    
    bool alt = true;
    int cnt_0 = 0;
    int cnt_1 = 0;
    for(int i = 1; i < n; i++) {
        if(S[i] == S[i - 1]) {
            alt = false;
            break;
        } 
    }

    if(alt) {
        std::cout << 0 << '\n';
        return;
    }

    for(char c : S) {
        if(c == '0') {
            cnt_0 += 1;
        } else {
            cnt_1 += 1;
        }
    }

    if(std::abs(cnt_0 - cnt_1) <= 1) {
        std::cout << 1 << '\n';
        return;
    }

    if(std::abs(cnt_0 - cnt_1) <= 3) {
        std::cout << 2 << '\n';
        return;
    }

    std::cout << 3 << '\n';
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
