#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;

    // A: rock B: Paper C: Scissors
    // X: Rock Y: Paper C: Scissors
    // X: lose Y: draw Z: win
    int score = 0;
    while(std::getline(std::cin, S)) {
        char c1 = S[0];
        char c2 = S[2];
        
        if(c1 == 'A') {
            if(c2 == 'Y') {
                score += 1 + 3;
            } else if(c2 == 'X') {
                score += 3;
            } else {
                score += 2 + 6;
            }
        } else if (c1 == 'B') {
            if(c2 == 'Y') {
                score += 2 + 3;
            } else if(c2 == 'X') {
                score += 1;
            } else {
                score += 3 + 6;
            }
        } else {
            if(c2 == 'Y') {
                score += 3 + 3; 
            } else if(c2 == 'X') {
                score += 2;
            } else {
                score += 1 + 6;
            }
        }
    }

    std::cout << score << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
