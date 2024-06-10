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

    if(N == K) {
        for(int i = 0; i < N; i++) {
            if(S[i] != S[0]) {
                std::cout << -1 << '\n';
                return;
            }
        }
        std::cout << N << '\n';
        return;
    }
    
    int last = 0;
    for(int i = N - 1; i >= 0; ) {
        int j = i;
        while(i >= 0 && S[i] == S[j]) {
            i -= 1;
        }

        if(j - i > K) {
            std::cout << -1 << '\n';
            return;
        }
    
        last = (j - i) % K;
        break;
    }

    std::vector<int> good(N, 0);
    good[N - 1 - last] = 1;
    int c = S[N - 1 - last] - '0';
    for(int i = N - 1 - last; i >= 0; ) {
        bool ok = true;
        for(int j = 0; j < K; j++) {
            if(i - j < 0) {
                ok = false;
                break;
            }
            if(S[i - j] - '0' != c) {
                ok = false;
                break;
            }
        }
        
        if(!ok) {
            break;
        }
        
        if(i - K >= 0) {
            good[i - K] = 1;
            i -= K;
            c ^= 1;
        } else {
            break;
        }
    }

    c = S[0] - '0';
    for(int i = 0; i < N; ) {
        bool ok = true;
        for(int j = 0; j < K; j++) {
            if(S[i + j] - '0' != c) {
                ok = false;
                break;
            }

            if(good[i + j] && last && S[i + j] == S.back() && j + 1 + last == K) {
                std::cout << i + j + 1 << '\n';
                return;
            }
        }
        
        if(ok) {
            if(!last) {
                if(good[i + K - 1] && S[i + K - 1] != S.back()) {
                    std::cout << i + K << '\n';
                    return;
                }
            }
            i += K;
            c ^= 1;
        } else {
            int p = -1;
            for(int j = 0; j < K; j++) {
                if(S[i + j] - '0' != c) {
                    p = i + j - 1;   
                    break;
                }
            }
            if(!good[p]) {
                break;
            }
            
            if(S[p] == S.back() && p - i + 1 + last == K) {
                std::cout << p + 1 << '\n';
                return;
            }
            
            break;
        }
    }

    std::cout << -1 << '\n';
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
