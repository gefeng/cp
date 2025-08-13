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

    for(int i = 0; i < K; i++) {
        std::array<int, 2> cnt = {};
        for(int j = i; j < N; j += K) {
            if(S[j] != '?') {
                cnt[S[j] - '0'] += 1;
            }
        }
        if(cnt[0] && cnt[1]) {
            std::cout << "NO" << '\n';
            return;
        }
        
        if(cnt[0]) {
            for(int j = i; j < N; j += K) {
                if(S[j] == '?') {
                    S[j] = '0';
                }
            }  
        } else if(cnt[1]) {
            for(int j = i; j < N; j += K) {
                if(S[j] == '?') {
                    S[j] = '1';
                }
            }  
        }
    }

    std::array<int, 2> cnt = {};
    for(int i = 0; i < K; i++) {
        if(S[i] != '?') {
            cnt[S[i] - '0'] += 1;
        }
    }
    
    std::cout << (cnt[0] <= K / 2 && cnt[1] <= K / 2 ? "YES" : "NO") << '\n';
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
