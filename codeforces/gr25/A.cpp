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
    
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += S[i] - '0'; 
    }
    
    if(cnt % 2 == 1) {
        std::cout << "No" << '\n';
        return;
    }

    if(cnt == 2) {
        for(int i = 0; i < N - 1; i++) {
            if(S[i] == '1' && S[i + 1] == '1') {
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
