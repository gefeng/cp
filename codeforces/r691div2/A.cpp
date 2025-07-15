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
    
    std::string S, T;
    std::cin >> S >> T;
    
    int cnt_a = 0;
    int cnt_b = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == T[i]) {
            continue;
        }
        if(S[i] > T[i]) {
            cnt_a += 1;
        } else {
            cnt_b += 1;
        }
    }

    if(cnt_a == cnt_b) {
        std::cout << "EQUAL" << '\n';
        return;
    }

    std::cout << (cnt_a > cnt_b ? "RED" : "BLUE") << '\n';
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
