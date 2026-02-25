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
    
    int st = N % 2;
    if(N % 2 == 1) {
        if(S[0] == 'b') {
            std::cout << "No" << '\n';
            return;
        }    
    }

    for(int i = st; i < N; i += 2) {
        if(S[i] == S[i + 1] && S[i] != '?') {
            std::cout << "No" << '\n';
            return;
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
