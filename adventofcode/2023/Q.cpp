#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = (int)2e9;
constexpr std::array<int, 4> DR = {-1, 0, 1, 0};
constexpr std::array<int, 4> DC = {0, 1, 0, -1};

std::vector<std::string> G;

int dijkstra(int sd, int min_move, int max_move) {
    int n = G.size();
    int m = G[0].size();

    auto cmp = [](auto& a, auto& b) {
        return a[3] > b[3];
    };

    std::priority_queue<std::array<int, 4>, std::vector<std::array<int, 4>>, decltype(cmp)> pq(cmp);
    std::vector<std::vector<std::vector<int>>> best(n, std::vector<std::vector<int>>(m, std::vector<int>(4, INF)));

    best[0][0][sd] = 0;
    pq.push({0, 0, sd, 0});

    while(!pq.empty()) {
        std::array<int, 4> cur = pq.top();
        pq.pop();

        int r = cur[0];
        int c = cur[1];
        int d = cur[2];
        int cost = cur[3];
        
        if(best[r][c][d] != cost) {
            continue;
        }
        
        int ncost = cost;
        for(int i = 1; i <= max_move; i++) {
            int nr = r + DR[d] * i;
            int nc = c + DC[d] * i;
            if(nr >= 0 && nc >= 0 && nr < n && nc < m) {
                ncost += G[nr][nc] - '0'; 
                
                if(i >= min_move) {
                    for(int j = -1; j <= 1; j += 2) {
                        int nd = (d + j + 4) % 4;
                        if(ncost < best[nr][nc][nd]) {
                            best[nr][nc][nd] = ncost;
                            pq.push({nr, nc, nd, ncost});
                        }
                    }
                }
            } else {
                break;
            }
        }
    }

    int ans = INF;
    for(int d = 0; d < 4; d++) {
        ans = std::min(ans, best[n - 1][m - 1][d]); 
    }

    return ans;
}

void run_case1() {
    int ans = INF;
    for(int d = 1; d <= 2; d++) {
        ans = std::min(ans, dijkstra(d, 1, 3)); 
    }
    std::cout << ans << '\n';
}

void run_case2() {
    int ans = INF;
    for(int d = 1; d <= 2; d++) {
        ans = std::min(ans, dijkstra(d, 4, 10)); 
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string S;
    while(std::getline(std::cin, S)) {
        G.push_back(S);
    }

    run_case1();
    run_case2();
}
