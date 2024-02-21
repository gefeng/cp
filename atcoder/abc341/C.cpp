#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int H, W, N;
    std::cin >> H >> W >> N;

    std::string T;
    std::cin >> T;
    
    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == '#') {
                continue;
            }
            int r = i;
            int c = j;
            bool ok = true;
            for(int k = 0; k < N; k++) {
                int d = 0;
                if(T[k] == 'R') {
                    d = 0; 
                } else if(T[k] == 'D') {
                    d = 1;
                } else if(T[k] == 'L') {
                    d = 2;
                } else {
                    d = 3;
                }

                int nr = r + DR[d];
                int nc = c + DC[d];
                if(nr >= 0 && nc >= 0 && nr < H && nc < W && G[nr][nc] != '#') {
                    r = nr;
                    c = nc;
                } else {
                    ok = false;
                    break;
                }
            } 

            if(ok) {
                ans += 1;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
