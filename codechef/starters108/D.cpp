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
        std::cout << "Yes" << '\n';
        return;
    }

    if(S.back() == S[N - 2]) {
        std::cout << "No" << '\n';
        return;
    }

    char t = S.back();
    char c = t == '0' ? '1' : '0';
    
    int cnt = 0;
    for(int i = N - 2; i >= 0; i--) {
        if(S[i] == t) {
            cnt += 1;
        } else {
            cnt -= 1;
        }

        if(cnt > 0) {
            std::cout << "No" << '\n';
            return;
        }
    }

    cnt = 0;
    for(int i = N - 3; i >= 0; i--) {
        if(S[i] == c) {
            cnt += 1;
        } else {
            cnt -= 1;
        }

        if(cnt > 1) {
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
