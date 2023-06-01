#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

const std::array<int, 4> DR = {0, 1, 0, -1};
const std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    std::vector<std::string> G;
    std::string S;
    while(std::getline(std::cin, S)) {
        G.push_back(S);
    }

    int n = G.size();
    int m = G[0].size();
    
    int sr = 0;
    int sc = 0;
    int tr = 0;
    int tc = 0;

    std::vector<std::vector<bool>> vis(n, std::vector<bool>(m, false));
    std::queue<std::pair<int, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == 'S' || G[i][j] == 'a') {
                q.emplace(i, j);
                vis[i][j] = true;
            }
            if(G[i][j] == 'E') {
                tr = i;
                tc = j;
            }
        } 
    }

    auto get_height = [](char c) {
        if(c == 'S') {
            return 0;
        }
        if(c == 'E') {
            return 25;
        }

        return c - 'a';
    };

    int ans = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            std::pair<int, int> cur = q.front();
            q.pop();
            int r = cur.first;
            int c = cur.second;
            int h = get_height(G[r][c]);

            if(tr == r && tc == c) {
                std::cout << ans << '\n';
                return;
            }

            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc]) {
                    int nh = get_height(G[nr][nc]);
                    if(nh - h <= 1) {
                        q.emplace(nr, nc);
                        vis[nr][nc] = true;
                    }
                }
            }
        }

        ans += 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
