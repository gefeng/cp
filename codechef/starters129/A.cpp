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

    if(N == 1) {
        std::cout << "Bob" << '\n';
        return;
    }

    if(N == 2) {
        std::cout << (S == "01" || S == "10" ? "Bob" : "Alice") << '\n';
        return;
    }
    
    if(N % 2 == 1) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            cnt += S[i] - '0';
        } 
        if(std::abs(cnt - (N - cnt)) == 1) {
            std::cout << "Alice" << '\n';
        } else {
            std::cout << "Bob" << '\n';
        }
    } else {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            cnt += S[i] - '0';
        } 

        if(cnt == N - cnt) {
            std::cout << "Bob" << '\n';
        } else {
            std::cout << "Alice" << '\n';
        }
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
