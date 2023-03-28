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

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(G[i][j] != '.' && G[i][j] != '#') {
                int p = G[i][j] - '0';

                for(int r = 0; r < N; r++) {
                    for(int c = 0; c < M; c++) {
                        if(abs(r - i) + abs(c - j) <= p && G[r][c] == '#') {
                            G[r][c] = '.'; 
                        }
                    }
                }

                G[i][j] = '.';
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << G[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
