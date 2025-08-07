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

    if(N % 2 == 1) {
        for(int i = 0; i < N; i += 2) {
            if((S[i] - '0') % 2 == 1) {
                std::cout << 1 << '\n';
                return;
            }
        }
        std::cout << 2 << '\n';
    } else {
        for(int i = 1; i < N; i += 2) {
            if((S[i] - '0') % 2 == 0) {
                std::cout << 2 << '\n';
                return;
            }
        }
        std::cout << 1 << '\n';
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
