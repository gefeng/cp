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

    std::string s = "";
    for(int i = 0; i < N; i++) {
        if(S[i] == 'S') {
            s.push_back('R');
        } else if(S[i] == 'P') {
            s.push_back('S');
        } else {
            s.push_back('P');
        }
    }

    std::string ans(N, 'P');
    int win = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'R') {
            win += 1;
        }
    }

    for(int i = N - 1; i >= 0 && win <= N / 2; i--) {
        if(S[i] == 'S') {
            ans[i] = 'R';
            win += 1;
        } else if(S[i] == 'P') {
            ans[i] = 'S';
            win += 1;
        }
    }

    std::cout << ans << '\n';
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
