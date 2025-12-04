#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S, T;
    std::cin >> S >> T;

    int p = N - M + 1;
    
    for(int i = p, j = 1; i < N; i++, j++) {
        if(S[i] != T[j]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    for(int i = 0; i < p; i++) {
        if(S[i] == T[0]) {
            std::cout << "Yes" << '\n';
            return;
        }
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
