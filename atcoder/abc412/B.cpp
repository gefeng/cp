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
    for(int i = 1; i < n; i++) {
        if(S[i] >= 'A' && S[i] <= 'Z') {
            if(T.find(S[i - 1]) == std::string::npos) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }
    
    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
