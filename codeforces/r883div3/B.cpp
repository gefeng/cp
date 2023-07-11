#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<std::string> A(3);
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    auto is_win = [&](char who) {
        for(int i = 0; i < 3; i++) {
            bool win = true;
            for(int j = 0; j < 3; j++) {
                if(A[i][j] != who) {
                    win = false; 
                }
            }

            if(win) {
                return true;
            }
        }

        for(int i = 0; i < 3; i++) {
            bool win = true;
            for(int j = 0; j < 3; j++) {
                if(A[j][i] != who) {
                    win = false; 
                }
            }

            if(win) {
                return true;
            }
        }

        bool win = true;
        for(int i = 0; i < 3; i++) {
            if(A[i][i] != who) {
                win = false;
            } 
        }

        if(win) {
            return true;
        }

        win = true;
        for(int i = 0; i < 3; i++) {
            if(A[i][2 - i] != who) {
                win = false;
            } 
        }

        if(win) {
            return true;
        }

        return false;
    };

    if(is_win('X')) {
        std::cout << 'X' << '\n';
        return;
    }
    if(is_win('O')) {
        std::cout << 'O' << '\n';
        return;
    }
    if(is_win('+')) {
        std::cout << '+' << '\n';
        return;
    }

    std::cout << "DRAW" << '\n';
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
