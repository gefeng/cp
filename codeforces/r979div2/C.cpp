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
    std::cin >> S;
    
    for(int i = 1; i < N; i++) {
        if(S[i - 1] == '1' && S[i] == '1') {
            std::cout << "Yes" << '\n';
            return;
        } 
    }

    if(S[0] == '1' || S.back() == '1') {
        std::cout << "Yes" << '\n';
        return;
    }

    std::cout << "No" << '\n';
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
