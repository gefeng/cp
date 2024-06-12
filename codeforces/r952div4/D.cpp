#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }

    int min_c = M;
    int max_c = 0;
    int min_r = N;
    int max_r = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(G[i][j] == '#') {
                min_r = std::min(min_r, i);
                max_r = std::max(max_r, i);
                min_c = std::min(min_c, j);
                max_c = std::max(max_c, j);
            } 
        }
    }

    std::cout << min_r + (max_r - min_r) / 2 + 1 << ' ' << min_c + (max_c - min_c) / 2 + 1 << '\n';
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
