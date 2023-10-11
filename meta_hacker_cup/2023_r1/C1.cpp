#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case(int T) {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int Q;
    std::cin >> Q;
    
    std::vector<int> cnt(N + 1, 0);
    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;
        cnt[X] += 1;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            if(cnt[i] & 1) {
                S[j - 1] = S[j - 1] == '0' ? '1' : '0';
            }
        } 
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(S[i - 1] == '1') {
            ans += 1;
            for(int j = i; j <= N; j += i) {
                S[j - 1] = S[j - 1] == '0' ? '1' : '0';
            }
        }
    }

    std::cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
