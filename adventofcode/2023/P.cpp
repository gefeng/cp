#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr std::array<int, 4> DR = {-1, 0, 1, 0};
constexpr std::array<int, 4> DC = {0, 1, 0, -1};

std::vector<std::string> G;

bool is_valid(int n, int m, int r, int c) {
    return r >= 0 && c >= 0 && r < n && c < m;
}

int solve(int sr, int sc, int sd) {
    int n = G.size();
    int m = G[0].size();

    std::vector<std::vector<std::vector<int>>> vis(n, std::vector<std::vector<int>>(n, std::vector<int>(4, 0)));
    std::queue<std::array<int, 3>> q;
    
    q.push({sr, sc, sd});
    vis[sr][sc][sd] = 1;

    auto push = [&](int r, int c, int d) {
        if(is_valid(n, m, r, c) && !vis[r][c][d]) {
            q.push({r, c, d}); 
            vis[r][c][d] = 1;
        }
    };
    
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            std::array<int, 3> cur = q.front();
            q.pop();

            int r = cur[0];
            int c = cur[1];
            int d = cur[2];

            int nd = 0;
            if(G[r][c] == '.') {
                push(r + DR[d], c + DC[d], d);
            } else if(G[r][c] == '|') {
                if(d == 0 || d == 2) {
                    push(r + DR[d], c + DC[d], d);
                } else {
                    for(int i = 0, nd = 0; i < 2; i++, nd += 2) {
                        push(r + DR[nd], c + DC[nd], nd);
                    }
                }
            } else if(G[r][c] == '-') {
                if(d == 1 || d == 3) {
                    push(r + DR[d], c + DC[d], d);
                } else {
                    for(int i = 0, nd = 1; i < 2; i++, nd += 2) {
                        push(r + DR[nd], c + DC[nd], nd);
                    }
                }
            } else if(G[r][c] == '\\') {
                if(d == 0 || d == 2) {
                    nd = (d - 1 + 4) % 4;
                } else {
                    nd = (d + 1) % 4;
                }
                push(r + DR[nd], c + DC[nd], nd);
            } else if(G[r][c] == '/') {
                if(d == 1 || d == 3) {
                    nd = (d - 1 + 4) % 4;
                } else {
                    nd = (d + 1) % 4;
                }
                push(r + DR[nd], c + DC[nd], nd);
            }
        }
    }

    int ans = 0;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < m; c++) {
            for(int d = 0; d < 4; d++) {
                if(vis[r][c][d]) {
                    ans += 1;
                    break;
                }
            }
        }
    }

    return ans;
}

void run_case1() {
    std::cout << solve(0, 0, 1) << '\n';
}

void run_case2() {
    int ans = 0;
    int n = G.size();
    int m = G[0].size();

    for(int i = 0; i < m; i++) {
        ans = std::max(ans, solve(0, i, 2));
        ans = std::max(ans, solve(n - 1, i, 0));
    }

    for(int i = 0; i < n; i++) {
        ans = std::max(ans, solve(i, 0, 1));
        ans = std::max(ans, solve(i, m - 1, 3));
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
