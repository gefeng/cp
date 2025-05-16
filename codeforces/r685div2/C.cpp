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

    std::string S, T;
    std::cin >> S >> T;
    
    std::array<int, 26> freq_s = {};
    std::array<int, 26> freq_t = {};

    for(int i = 0; i < N; i++) {
        freq_s[S[i] - 'a'] += 1;
        freq_t[T[i] - 'a'] += 1;
    }

    for(int i = 0; i < 26; i++) {
        if(freq_s[i] == freq_t[i]) {
            freq_s[i] = 0;
            freq_t[i] = 0;
            continue;
        } 

        if(freq_s[i] < freq_t[i]) {
            std::cout << "No" << '\n';
            return;
        }

        if(i + 1 < 26) {
            int d = freq_s[i] - freq_t[i];
            if(d % K != 0) {
                std::cout << "No" << '\n';
                return;
            }
            freq_s[i + 1] += d;
            freq_s[i] = 0;
            freq_t[i] = 0;
        } else {
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
