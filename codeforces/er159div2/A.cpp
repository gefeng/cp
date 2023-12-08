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
        if(S[i] != S[i - 1]) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += S[i] == '0' ? 1 : 0;
    }

    if(cnt > N - cnt) {
        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
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
