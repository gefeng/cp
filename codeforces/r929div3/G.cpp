#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

constexpr int MAX_R = 5;
constexpr int MAX_C = 5;

void dfs(std::vector<std::vector<int>>& G, int r, int c) {
    if(r == MAX_R) {
        for(int i = 0; i < MAX_R; i++) {
            for(int j = 0; j < MAX_C; j++) {
                std::cout << G[i][j];
            }
            std::cout << '\n';
        }
        std::cout << '\n';
        return;
    }

    for(int i = 0; i < 2; i++) {
        if(c - 1 >= 0 && c - 2 >= 0 && G[r][c - 1] == i && G[r][c - 2] == i) {
            continue;
        } 
        if(r - 1 >= 0 && r - 2 >= 0 && G[r - 1][c] == i && G[r - 2][c] == i) {
            continue;
        }
        if(r - 1 >= 0 && c - 1 >= 0 && r - 2 >= 0 && c - 2 >= 0 && G[r - 1][c - 1] == i && G[r - 2][c - 2] == i) {
            continue;
        }
        if(r - 1 >= 0 && c + 1 < MAX_C && r - 2 >= 0 && c + 2 < MAX_C && G[r - 1][c + 1] == i && G[r - 2][c + 2] == i) {
            continue;
        }
        G[r][c] = i;
        int nr = r;
        int nc = c + 1;
        if(nc == MAX_C) {
            nc = 0;
            nr += 1;
        } 
        dfs(G, nr, nc);
        G[r][c] = 0;
    }
}

void run_case() {
    int N, M, Q;
    std::cin >> N >> M >> Q;
    
    //std::vector<std::vector<int>> G(MAX_R, std::vector<int>(MAX_C, 0)); 
    //dfs(G, 0, 0);
    
    std::vector<std::vector<std::vector<int>>> all = {
        {{0, 0, 1, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}, {1, 1, 0, 0}}, 
        {{0, 1, 0, 1}, {0, 1, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 0}}, 
        {{0, 1, 0, 1}, {1, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 1}}, 
        {{0, 1, 1, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}, {1, 0, 0, 1}}, 
        {{1, 0, 0, 1}, {0, 1, 1, 0}, {1, 0, 0, 1}, {0, 1, 1, 0}}, 
        {{1, 0, 1, 0}, {0, 1, 0, 1}, {0, 1, 0, 1}, {1, 0, 1, 0}}, 
        {{1, 0, 1, 0}, {1, 0, 1, 0}, {0, 1, 0, 1}, {0, 1, 0, 1}}, 
        {{1, 1, 0, 0}, {0, 0, 1, 1}, {1, 1, 0, 0}, {0, 0, 1, 1}}
    };

    int mask = (1 << 8) - 1;

    std::cout << 8 << '\n';
    for(int i = 0; i < Q; i++) {
        int R, C;
        std::string S;
        std::cin >> R >> C >> S;

        if(mask == 0) {
            std::cout << 0 << '\n';
            continue;
        }

        R -= 1;
        C -= 1;
        R %= 4;
        C %= 4;
        int nmask = 0;
        int t = S == "circle" ? 0 : 1;
        for(int j = 0; j < 8; j++) {
            if((mask & (1 << j)) && all[j][R][C] == t) {
                nmask |= 1 << j; 
            }
        } 

        std::swap(mask, nmask);
        std::cout << __builtin_popcount(mask) << '\n'; 
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
