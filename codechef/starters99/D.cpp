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

    int cnt_one = 0;
    for(int i = 0; i < N; i++) {
        cnt_one += S[i] - '0';
    }

    if(cnt_one == 0 || cnt_one == N) {
        std::cout << S << '\n';
        return;
    }

    if(cnt_one == 1) {
        if(S[0] == '1') {
            for(int i = 0; i < N - 1; i++) {
                S[i] = '1';
            } 
        } else if(S.back() == '1') {
            for(int i = 1; i < N; i++) {
                S[i] = '1';
            }
        } else {
            for(int i = 1; i < N - 1; i++) {
                S[i] = '1';
            }
        }

        std::cout << S << '\n';
        return;
    }

    bool move = false;
    for(int i = 1; i < N - 1; i++) {
        int l = S[i - 1] - '0';
        int m = S[i] - '0';
        int r = S[i + 1] - '0';
        if(m != (l ^ r)) {
            move = true;
            break;
        }
    }

    if(move) {
        if(S[0] == '1' && S.back() == '1') {
            S[1] = '0';
            for(int i = 2; i < N - 1; i++) {
                S[i] = '1';
            }
        } else {
            for(int i = 1; i < N - 1; i++) {
                S[i] = '1';
            } 
        }
    }

    std::cout << S << '\n';
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
