#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, D;
    std::cin >> N >> D;
    
    std::string S;
    std::cin >> S;

    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == '@' && D > 0) {
            S[i] = '.';
            D -= 1;
        }
    }

    std::cout << S << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
