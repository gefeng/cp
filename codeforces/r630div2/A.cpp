#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, C, D;
    std::array<int, 6> P;

    std::cin >> A >> B >> C >> D;
    
    for(int i = 0; i < 6; i++) {
        std::cin >> P[i];
    }

    if(A == B) {
        if(A && P[0] == P[2] && P[0] == P[4]) {
            std::cout << "No" << '\n';
            return;
        }
    } else if(A > B) {
        int d = A - B;
        if(P[0] - d < P[2]) {
            std::cout << "No" << '\n';
            return;
        }
    } else {
        int d = B - A;
        if(P[0] + d > P[4]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    if(C == D) {
        if(C && P[1] == P[3] && P[1] == P[5]) {
            std::cout << "No" << '\n';
            return;
        }
    } else if(C > D) {
        int d = C - D;
        if(P[1] - d < P[3]) {
            std::cout << "No" << '\n';
            return;
        }
    } else {
        int d = D - C;
        if(P[1] + d > P[5]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
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
