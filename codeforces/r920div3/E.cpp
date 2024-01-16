#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, W, X1, Y1, X2, Y2;
    std::cin >> H >> W >> X1 >> Y1 >> X2 >> Y2;
    
    if(X1 >= X2) {
        std::cout << "Draw" << '\n';
        return;
    }

    int d = X2 - X1;

    if(d % 2 == 1) {
        int move = (d - 1) / 2;
        int l1 = Y1 - 1;
        int r1 = W - Y1;
        int l2 = Y2 - 1;
        int r2 = W - Y2;
        //int need = std::abs(Y1 - Y2);
        //std::cout << (need <= move ? "Alice" : "Draw") << '\n';
        
        if(Y1 < Y2) {
            // move to the right
            int can_move = std::min(move, r2);
            int p2 = Y2 + can_move;
            int p1 = Y1 + can_move;
            p1 += std::min(W - p1, move - can_move);
            std::cout << (std::abs(p1 - p2) <= 1 ? "Alice" : "Draw") << '\n';
        } else {
            int can_move = std::min(move, l2);
            int p2 = Y2 - can_move;
            int p1 = Y1 - can_move;
            p1 -= std::min(p1 - 1, move - can_move);
            std::cout << (std::abs(p1 - p2) <= 1 ? "Alice" : "Draw") << '\n';
        }
    } else {
        int move = d / 2;
        int l1 = Y1 - 1;
        int r1 = W - Y1;
        int l2 = Y2 - 1;
        int r2 = W - Y2;

        if(Y1 < Y2) {
            // move to the left
            int can_move = std::min(move, l1);
            int p2 = Y2 - can_move;
            int p1 = Y1 - can_move;
            p2 -= std::min(p2 - 1, move - can_move);
            std::cout << (p1 == p2 ? "Bob" : "Draw") << '\n';
        } else {
            int can_move = std::min(move, r1);
            int p2 = Y2 + can_move;
            int p1 = Y1 + can_move;
            p2 += std::min(W - p2, move - can_move);
            std::cout << (p1 == p2 ? "Bob" : "Draw") << '\n';
        }
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
