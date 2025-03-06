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

    if(N == 1) {
        std::cout << "Yes" << '\n';
        return;
    }
    
    int cnt_0 = 0;
    int cnt_1 = 0;
    int cnt_01 = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '0' && T[i] == '0') {
            cnt_0 += 1;
            cnt_0 %= 2;
        } else if(S[i] == '1' && T[i] == '1') {
            cnt_1 += 1;
            cnt_1 %= 2;
        } else {
            cnt_01 += 1;
            cnt_01 %= 2;
        }
    }

    if(cnt_0 && cnt_1 && cnt_01) {
        std::cout << "No" << '\n';
        return;
    }

    if(!cnt_0 && !cnt_1 && !cnt_01) {
        std::cout << "Yes" << '\n';
        return;
    }

    if((cnt_0 && !cnt_1 && !cnt_01) || (!cnt_0 && cnt_1 && !cnt_01)) {
        std::cout << "Yes" << '\n';
        return;
    }

    if(!cnt_0 && !cnt_1 && cnt_01) {
        std::cout << "Yes" << '\n';
        return;
    }

    std::cout << "No" << '\n';
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
