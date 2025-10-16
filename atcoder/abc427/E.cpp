#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> G(H);
    int pr = -1;
    int pc = -1;
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
        for(int j = 0; j < W; j++) {
            if(G[i][j] == 'T') {
                pr = i;
                pc = j;
            }
        }
    }

    auto check = [&](std::vector<std::string>& g) {
        for(int r = 0; r < H; r++) {
            for(int c = 0; c < W; c++) {
                if(g[r][c] == '#') {
                    return false;
                }
            }
        }
        return true;
    };
    
    std::queue<std::vector<std::string>> q;
    std::map<std::vector<std::string>, int> m;

    q.push(G);
    m[G] = 0;
    
    while(!q.empty()) {
        std::vector<std::string> g = q.front();
        q.pop();

        if(check(g)) {
            std::cout << m[g] << '\n';
            return;
        }

        for(int i = 0; i < 4; i++) {
            std::vector<std::string> nxt(H, std::string(W, '.'));
            nxt[pr][pc] = 'T';
            bool good = true;
            for(int r = 0; r < H; r++) {
                for(int c = 0; c < W; c++) {
                    if(g[r][c] != '#') {
                        continue;
                    }
                    int nr = r + DR[i];
                    int nc = c + DC[i];
                    if(nr >= 0 && nc >= 0 && nr < H && nc < W) {
                        if(nxt[nr][nc] == 'T') {
                            good = false;
                            break;
                        }
                        nxt[nr][nc] = '#';
                    }
                }
                if(!good) {
                    break;
                }
            }

            if(good && m.find(nxt) == m.end()) {
                m[nxt] = m[g] + 1;
                q.push(nxt);
            }
        }
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
