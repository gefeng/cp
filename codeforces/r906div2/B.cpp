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

    bool good = true;
    for(int i = 1; i < N; i++) {
        if(S[i] == S[i - 1]) {
            good = false;
            break;
        }
    }

    if(good) {
        std::cout << "Yes" << '\n';
        return;
    }

    good = true;
    for(int i = 1; i < M; i++) {
        if(T[i] == T[i - 1]) {
            good = false;
            break;
        }
    }

    if(!good) {
        std::cout << "No" << '\n';
        return;
    }

    for(int i = 1; i < N; i++) {
        if(S[i] == S[i - 1]) {
            if(S[i - 1] == T[0] || S[i] == T.back()) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

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
