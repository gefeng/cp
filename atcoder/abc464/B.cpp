#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, W;
    std::cin >> H >> W;
    
    std::vector<std::string> A(H);
    for(int i = 0; i < H; i++) {
        std::cin >> A[i];
    }

    int sr = H;
    int tr = 0;
    int sc = W;
    int tc = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(A[i][j] == '#') {
                sr = std::min(sr, i);
                sc = std::min(sc, j);
                tr = std::max(tr, i);
                tc = std::max(tc, j);
            }
        }
    }

    for(int i = sr; i <= tr; i++) {
        for(int j = sc; j <= tc; j++) {
            std::cout << A[i][j];
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
