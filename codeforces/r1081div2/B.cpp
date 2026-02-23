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

    int cnt0 = std::ranges::count(S, '0');
    int cnt1 = N - cnt0;
    
    if(cnt0 % 2 == 1) {
        std::cout << cnt0 << '\n';
        for(int i = 0; i < N; i++) {
            if(S[i] == '0') {
                std::cout << i + 1 << ' ';
            }
        }
        std::cout << '\n';
    } else if(cnt1 % 2 == 0) {
        std::cout << cnt1 << '\n';
        for(int i = 0; i < N; i++) {
            if(S[i] == '1') {
                std::cout << i + 1 << ' ';
            }
        }
        std::cout << '\n';
    } else {
        std::cout << -1 << '\n';
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
