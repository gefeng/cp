#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    // 4444943
    // 4444493
    
    int N, D;
    std::cin >> N >> D;
    
    std::string S;
    std::cin >> S;

    for(int i = 0; i < N; i++) {
        if(S[i] - '0' < D) {
            std::cout << S.substr(0, i) + std::to_string(D) + S.substr(i, N - i) << '\n';
            return;
        }
    }

    std::cout << S + std::to_string(D) << '\n';
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
