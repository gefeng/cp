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
    std::string T;
    std::cin >> S >> T;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            if(S[i] == '0') {
                cnt += 1;
            }
        } else {
            if(T[i] == '0') {
                cnt += 1;
            }
        }
    }

    if(cnt < (N + 1) / 2) {
        std::cout << "No" << '\n';
        return;
    }

    cnt = 0;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            if(T[i] == '0') {
                cnt += 1;
            }
        } else {
            if(S[i] == '0') {
                cnt += 1;
            }
        }
    }

    if(cnt < N / 2) {
        std::cout << "No" << '\n';
        return;
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
