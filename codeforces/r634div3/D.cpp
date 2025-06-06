#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<std::string> A(9);
    for(int i = 0; i < 9; i++) {
        std::cin >> A[i];
    }

    A[0][0] = A[0][0] == '1' ? '2' : '1';
    A[1][3] = A[1][3] == '1' ? '2' : '1';
    A[2][6] = A[2][6] == '1' ? '2' : '1';
    A[3][1] = A[3][1] == '1' ? '2' : '1';
    A[4][4] = A[4][4] == '1' ? '2' : '1';
    A[5][7] = A[5][7] == '1' ? '2' : '1';
    A[6][2] = A[6][2] == '1' ? '2' : '1';
    A[7][5] = A[7][5] == '1' ? '2' : '1';
    A[8][8] = A[8][8] == '1' ? '2' : '1';

    for(int i = 0; i < 9; i++) {
        std::cout << A[i] << '\n';
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
