#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    int cnt_0 = 0;
    int cnt_1 = 0;
    for(int i = 0; i < N; i++) {
        cnt_1 += S[i] - '0'; 
    }
    cnt_0 += N - cnt_1;
    
    while(K) {
        if(cnt_1 > 1 && cnt_1 > cnt_0) {
            cnt_1 -= 2;
            K -= 1;
            continue;
        }
        if(cnt_0 > 1 && cnt_0 > cnt_1) {
            cnt_0 -= 2;
            K -= 1;
            continue;
        }
        if(cnt_0 == cnt_1 && cnt_0 > 1) {
            cnt_0 -= 2;
            K -= 1;
            continue;
        }
        break;
    }

    if(K) {
        std::cout << "No" << '\n';
        return;
    }

    if((cnt_0 + cnt_1) % 2 == 0) {
        std::cout << (cnt_0 == cnt_1 ? "Yes" : "No") << '\n';
    } else {
        std::cout << (std::abs(cnt_0 - cnt_1) == 1 ? "Yes" : "No") << '\n';
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
