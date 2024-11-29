#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int X, Y;
    std::cin >> X >> Y;
    
    std::string S;
    std::cin >> S;

    int n = S.size();
    int x = 0;
    int y = 0;
    for(int i = 0; i < n; i++) {
        if(S[i] == 'U') {
            y += 1;
        } else if(S[i] == 'D') {
            y -= 1;
        } else if(S[i] == 'R') {
            x += 1;
        } else {
            x -= 1;
        }
    }

    int dx = X - x;
    int dy = Y - y;
    
    for(int i = 0; i < n; i++) {
        if(S[i] == 'U') {
            if(dy < 0) {
                dy += 1;
            }
        } else if(S[i] == 'D') {
            if(dy > 0) {
                dy -= 1;
            }
        } else if(S[i] == 'R') {
            if(dx < 0) {
                dx += 1;
            }
        } else {
            if(dx > 0) {
                dx -= 1;
            }
        }
    }
    
    std::cout << (dx == 0 && dy == 0 ? "YES" : "NO") << '\n';
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
