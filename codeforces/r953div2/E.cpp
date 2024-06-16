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
    std::cin >> S >> T;

    for(int i = 0; i < N; i++) {
        if(S[i] == '0' && i + 2 < N && S[i + 2] == '0' && T[i + 1] == '0') {
            T[i + 1] = '?';
        }
    }

    for(int i = 0; i < N; i++) {
        if(T[i] == '1' && i + 2 < N && T[i + 2] == '1' && S[i + 1] == '0') {
            S[i + 1] = '?';
        }
    }

    for(int i = 0; i < N; i++) {
        if(i + 2 < N && (T[i] == '1' || T[i] == '?') && (T[i + 2] == '1' || T[i + 2] == '?') && S[i + 1] == '0') {
            S[i + 1] = '*';
        }
    }

    std::vector<int> psum1(N + 1, 0);
    std::vector<int> psum2(N + 1, 0);
    std::vector<int> psum3(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum1[i + 1] = psum1[i] + (S[i] == '1' ? 1 : 0);
    }

    for(int i = 0; i < N; i++) {
        psum2[i + 1] = psum2[i] + (S[i] == '?' ? 1 : 0);
    }

    for(int i = 0; i < N; i++) {
        psum3[i + 1] = psum3[i] + (S[i] == '*' ? 1 : 0);
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
        int len = R - L + 1;
        
        int res = psum1[R + 1] - psum1[L] + psum2[R + 1] - psum2[L] + psum3[R + 1] - psum3[L];
        
        if(S[L] == '?' || S[L] == '*') {
            res -= 1;
        }
        
        if(len > 1 && (S[R] == '?' || S[R] == '*')) {
            res -= 1;
        }

        if(len > 2 && S[L + 1] == '*' && T[L] == '?') {
            res -= 1; 
        }

        if(len > 2 && S[R - 1] == '*' && T[R] == '?') {
            res -= 1;
        }

        if(len == 3 && S[L + 1] == '*' && T[L] == '?' && T[R] == '?') {
            res += 1;
        }

        std::cout << res << '\n';
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
