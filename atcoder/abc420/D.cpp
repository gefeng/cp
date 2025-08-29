#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};
constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> A(H);
    for(int i = 0; i < H; i++) {
        std::cin >> A[i];
    }
    
    int sr, sc;
    int tr, tc;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(A[i][j] == 'S') {
                sr = i;
                sc = j;
                A[i][j] = '.';
            }
            if(A[i][j] == 'G') {
                tr = i;
                tc = j;
                A[i][j] = '.';
            }
        }
    }

    std::queue<std::tuple<int, int, int>> q;
    std::vector<std::vector<std::vector<int>>> dist(2, std::vector<std::vector<int>>(H, std::vector<int>(W, INF)));
    q.emplace(sr, sc, 0);
    dist[0][sr][sc] = 0;
    
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            auto [r, c, s] = q.front();
            q.pop();
            
            if(r == tr && c == tc) {
                std::cout << dist[s][r][c] << '\n';
                return;
            }

            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                if(nr >= 0 && nc >= 0 && nr < H && nc < W && A[nr][nc] != '#') {
                    if((A[nr][nc] == 'o' && s == 0) || (A[nr][nc] == 'x' && s == 1) || A[nr][nc] == '.') {
                        int nd = dist[s][r][c] + 1;
                        if(nd < dist[s][nr][nc]) {
                            dist[s][nr][nc] = nd;
                            q.emplace(nr, nc, s);
                        }
                    } else if(A[nr][nc] == '?') {
                        int nd = dist[s][r][c] + 1;
                        int ns = s ^ 1;
                        if(nd < dist[ns][nr][nc]) {
                            dist[ns][nr][nc] = nd;
                            q.emplace(nr, nc, ns);
                        }
                    }
                }
            }
        }
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
