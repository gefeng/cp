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

    if(S[0] == S.back() && S[0] == 'I') {
        int p1 = 0;
        int p2 = N - 1;
        while(p1 < N && S[p1] == 'I') {
            p1 += 1;
        }
        while(p2 >= 0 && S[p2] == 'I') {
            p2 -= 1;
        }
        if(p1 <= p2) {
            for(int i = 0; i < p1; i++) {
                S[i] = S[p1];
            }
            for(int i = N - 1; i > p2; i--) {
                S[i] = S[p2];
            }
        } else {
            for(int i = 0; i < N; i++) {
                S[i] = 'A';
            }
        }
    }
    
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[i] == S[j]) {
            i += 1;
        }
        if(S[j] == 'I') {
            char c = j == 0 ? S[i] : S[j - 1];
            for(int k = j; k < i; k++) {
                S[k] = c;
            }
        }
    }

    int64_t score = 0;
    for(int i = 0; i < N - 1; i++) {
        if(S[i] == S[i + 1]) {
            score += 1;
        }
    }
    
    score *= K;
    if(S[0] == S.back()) {
        score += K - 1;
    }

    std::cout << score << '\n';
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
