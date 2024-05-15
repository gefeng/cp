#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <deque>

constexpr int INF = (int)1e9;
constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    } 

    std::deque<std::array<int, 3>> deq;
    std::vector<std::vector<int>> best(N, std::vector<int>(M, INF));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i == 0 || j == 0 || i == N - 1 || j == M - 1) {
                if(G[i][j] == '0') {
                    deq.push_front({i, j, 0});
                    best[i][j] = 0;
                } else {
                    deq.push_back({i, j, 1});
                    best[i][j] = 1;
                }
            }
        }
    }

    while(!deq.empty()) {
        std::array<int, 3> cur = deq.front();
        deq.pop_front();
        int r = cur[0];
        int c = cur[1];
        int d = cur[2];
        if(best[r][c] != d) {
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + DR[i];
            int nc = c + DC[i];
            if(nr >= 0 && nc >= 0 && nr < N && nc < M) {
                int nd = d + G[nr][nc] - '0';
                if(best[nr][nc] > nd) {
                    best[nr][nc] = nd;
                    if(nd == d) {
                        deq.push_front({nr, nc, nd});
                    } else {
                        deq.push_back({nr, nc, nd});
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(G[i][j] == '0') {
                ans = std::max(ans, best[i][j]);
            }
        }
    }

    std::cout << ans << '\n';
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
