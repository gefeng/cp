#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    std::vector<std::string> G;
    for(std::string S; std::getline(std::cin, S); ) {
        G.push_back(S); 
    }

    int n = G.size();
    int m = G[0].size();

    int sr = -1;
    int sc = -1;
    int tr = -1;
    int tc = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(G[i][j] == 'S') {
                sr = i;
                sc = j;
                G[i][j] = '.';
            }
            if(G[i][j] == 'E') {
                tr = i;
                tc = j;
                G[i][j] = '.';
            }
        }
    }

    auto bfs = [&]() {
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<int>> time(n, std::vector<int>(m, -1));
        
        q.emplace(sr, sc);
        time[sr][sc] = 0;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int t = time[r][c];

            if(r == tr && c == tc) {
                continue;
            }

            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && G[nr][nc] != '#') {
                    if(time[nr][nc] == -1) {
                        time[nr][nc] = t + 1;
                        q.emplace(nr, nc);
                    }
                }
            }
        }
        return time[tr][tc];
    };

    int t = bfs();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == '#') {
                G[i][j] = '.';
                int x = bfs();
                if(t - x >= 100) {
                    ans += 1;
                }
                G[i][j] = '#';
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
