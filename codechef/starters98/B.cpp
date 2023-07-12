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

    bool is_pal = true;
    for(int l = 0, r = N - 1; l < r; l++, r--) {
        if(S[l] != S[r]) {
            is_pal = false;
            break;
        }
    }

    if(is_pal) {
        std::cout  << "Yes" << '\n';
        return;
    }

    if(N % 3 == 1) {
        std::cout << "Yes" << '\n';
        return;
    }

    if(N % 3 == 0) {
        std::array<int, 26> cnt = {};
        for(int i = 0; i < N; i++) {
            if(i % 3 == 2) {
                cnt[S[i] - 'a'] += 1; 
            }
        }

        for(int i = 0; i < N; i += 3) {
            if(cnt[S[i] - 'a']) {
                std::cout << "Yes" << '\n';
                return;
            }

            if(i + 2 < N) {
                cnt[S[i + 2] - 'a'] -= 1;
            }
        }
    } else {
        std::array<int, 26> cnt = {};
        for(int i = 0; i < N; i++) {
            if(i % 3 == 1) {
                cnt[S[i] - 'a'] += 1;
            }
        }

        for(int i = 0; i < N; i += 3) {
            if(cnt[S[i] - 'a']) {
                std::cout << "Yes" << '\n';
                return;
            }

            if(i + 1 < N) {
                cnt[S[i + 1] - 'a'] -= 1;
            }
        }
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
