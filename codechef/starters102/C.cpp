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
    std::cin >> T >> S;

    if(S == T) {
        std::cout << (int64_t)(N + 1) * N / 2 << '\n';
        return;
    } 

    bool is_flipped = true;
    for(int i = 0; i < N; i++) {
        if(S[i] == T[i]) {
            is_flipped = false;
            break;
        }
    }

    if(is_flipped) {
        std::cout << (int64_t)(N - 1) * 2 << '\n';
        return;
    }

    int cnt = 0;
    for(int i = 0; i < N; ) {
        if(S[i] != T[i]) {
            while(i < N && S[i] != T[i]) {
                i += 1;
            }
            cnt += 1;
        } else {
            i += 1;
        }
    }

    if(cnt > 2) {
        std::cout << 0 << '\n';
        return;
    }

    if(cnt == 1) {
        int l = 0;
        int r = 0;
        for(int i = 0; i < N && S[i] == T[i]; i += 1, l += 1) {}
        for(int i = N - 1; i >= 0 && S[i] == T[i]; i -= 1, r += 1) {}

        std::cout << (int64_t)(l + r + N - r - l - 1) * 2 << '\n';
        return;
    }

    if(cnt == 2) {
        std::cout << 6 << '\n';
        return;
    }

    std::cout << 0 << '\n';
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
