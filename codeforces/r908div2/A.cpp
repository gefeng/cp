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

    int cnt_a = 0;
    int cnt_b = 0;
    for(int x = 1; x <= N; x++) {
        for(int y = 1; y <= N; y++) {
            int a = 0;
            int b = 0;
            int a_win = 0;
            int b_win = 0;
            int winner = -1;
            for(int i = 0; i < N; i++) {
                if(S[i] == 'A') {
                    a_win += 1;
                } else {
                    b_win += 1;
                }

                if(a_win == x) {
                    a += 1;
                    if(i == N - 1 && a == y && b < y) {
                        winner = 0;
                    }
                    a_win = 0;
                    b_win = 0;
                } else if(b_win == x) {
                    b += 1;
                    if(i == N - 1 && b == y && a < y) {
                        winner = 1;
                    }
                    a_win = 0;
                    b_win = 0;
                }
            } 

            if(winner == 0) {
                cnt_a += 1;
            } else if(winner == 1) {
                cnt_b += 1;
            }
        }
    }

    if(cnt_a && cnt_b) {
        std::cout << "?" << '\n';
        return;
    }

    std::cout << (cnt_a ? "A" : "B") << '\n';
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
