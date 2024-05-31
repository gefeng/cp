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
        if(S[i] >= '0' && S[i] <= '9' && S[i - 1] >= 'a' && S[i - 1] <= 'z') {
            std::cout << "No" << '\n';
            return;
        } 
    }

    int pre_d = -1;
    int pre_c = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] >= '0' && S[i] <= '9') {
            if(pre_d != -1 && S[i] - '0' < pre_d) {
                std::cout << "No" << '\n';
                return;
            } 
            pre_d = S[i] - '0';
        } else {
            if(pre_c != -1 && S[i] - 'a' < pre_c) {
                std::cout << "No" << '\n';
                return;
            }
            pre_c = S[i] - 'a';
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
