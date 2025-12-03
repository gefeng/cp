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

    int cnt0 = 0;
    int cnt1 = 0;
    for(int i = 0; i < N; i++) {
        cnt1 += S[i] - '0';
    }
    cnt0 = N - cnt1;

    if(cnt0 == 0 || cnt1 == 0) {
        std::cout << "No" << '\n';
        return;
    }

    for(int i = 0; i < K; i++) {
        int len = 0;
        for(int j = i; j < N; j += K) {
            len += 1;
        }
        cnt0 -= len / 2;
        cnt1 -= len / 2;
        if(len % 2 == 1) {
            if(cnt0 > cnt1) {
                cnt0 -= 1;
            } else {
                cnt1 -= 1;
            }
        }
        if(cnt0 < 0 || cnt1 < 0) {
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
