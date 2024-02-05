#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr std::array<int, 4> DR = {0, 1, -1, 0};
constexpr std::array<int, 4> DC = {1, 0, 0, -1};

int dfs(int N, std::vector<std::string>& G, int r1, int c1, int r2, int c2, int d, std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>>& dp) {
    if(r1 == r2 && c1 == c2) {
        return 0;
    }

    if(dp[r1][c1][r2][c2][d] != -2) {
        return dp[r1][c1][r2][c2][d];
    }

    int res = -1;
    //std::cout << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << '\n';
    int od = d == 4 ? d : (d + 2) % 4;
    for(int i = 0; i < 4; i++) {
        if(i == od) {
            continue;
        } 
        int nr1 = r1 + DR[i];
        int nc1 = c1 + DC[i];
        int nr2 = r2 + DR[i];
        int nc2 = c2 + DC[i];
        if(nr1 < 0 || nc1 < 0 || nr1 >= N || nc1 >= N || G[nr1][nc1] == '#') {
            nr1 = r1;
            nc1 = c1;
        }

        if(nr2 < 0 || nc2 < 0 || nr2 >= N || nc2 >= N || G[nr2][nc2] == '#') {
            nr2 = r2;
            nc2 = c2;
        }

        if(nr1 == r1 && nc1 == c1 && nr2 == r2 && nc2 == c2) {
            continue;
        }

        res = std::min(res, dfs(N, G, nr1, nc1, nr2, nc2, i, dp) + 1);
    } 

    return dp[r1][c1][r2][c2][d] = res;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }

    int sr1 = -1;
    int sc1 = -1;
    int sr2 = -1;
    int sc2 = -1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(G[i][j] == 'P') {
                if(sr1 == -1) {
                    sr1 = i;
                    sc1 = j;
                } else {
                    sr2 = i;
                    sc2 = j;
                }
            }
        }
    }

    /*std::vector<std::vector<std::vector<std::vector<std::vector<int>>>>> dp(N, 
            std::vector<std::vector<std::vector<std::vector<int>>>>(N, 
                std::vector<std::vector<std::vector<int>>>(N, 
                    std::vector<std::vector<int>>(N, std::vector<int>(5, -2)))));*/

    //std::cout << dfs(N, G, r1, c1, r2, c2, 4, dp) << '\n';

    std::vector<std::vector<std::vector<std::vector<int>>>> vis(N, 
            std::vector<std::vector<std::vector<int>>>(N, 
                std::vector<std::vector<int>>(N, 
                    std::vector<int>(N, 0))));
    std::queue<std::array<int, 4>> q;
    q.push({sr1, sc1, sr2, sc2});
    vis[sr1][sc1][sr2][sc2] = 1;
    
    int d = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            std::array<int, 4> cur = q.front();
            q.pop();
            int r1 = cur[0];
            int c1 = cur[1];
            int r2 = cur[2];
            int c2 = cur[3];

            if(r1 == r2 && c1 == c2) {
                std::cout << d << '\n';
                return;
            }

            for(int i = 0; i < 4; i++) {
                int nr1 = r1 + DR[i];
                int nc1 = c1 + DC[i];
                int nr2 = r2 + DR[i];
                int nc2 = c2 + DC[i];
                if(nr1 < 0 || nc1 < 0 || nr1 >= N || nc1 >= N || G[nr1][nc1] == '#') {
                    nr1 = r1;
                    nc1 = c1;
                }

                if(nr2 < 0 || nc2 < 0 || nr2 >= N || nc2 >= N || G[nr2][nc2] == '#') {
                    nr2 = r2;
                    nc2 = c2;
                }

                if(!vis[nr1][nc1][nr2][nc2]) {
                    q.push({nr1, nc1, nr2, nc2});
                    vis[nr1][nc1][nr2][nc2] = 1;
                }
            }
        }

        d += 1;
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
