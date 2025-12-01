#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

bool dfs(std::vector<std::string>& G, int r, int c, int d, std::vector<std::array<int, 3>>& vis) {
    if(G[r][c] == '.') {
        return true;
    }
    if(G[r][c] == '#') {
        return false;
    }

    if(G[r][c] == '[') {
        vis.push_back({r, c, 0});
    } else {
        vis.push_back({r, c, 1});
    }

    if(d == 1 || d == 3) {
        int nr = r + DR[d];
        int nc = c + DC[d];
        if(G[nr][nc] == ']') {
            bool lhs = dfs(G, nr, nc - 1, d, vis);
            bool rhs = dfs(G, nr, nc, d, vis);
            if(!lhs || !rhs) {
                return false;
            }
        } else if(G[nr][nc] == '[') {
            bool lhs = dfs(G, nr, nc, d, vis);
            bool rhs = dfs(G, nr, nc + 1, d, vis);
            if(!lhs || !rhs) {
                return false;
            }
        } else {
            if(!dfs(G, nr, nc, d, vis)) {
                return false;
            }
        }
    } else {
        if(!dfs(G, r + DR[d], c + DC[d], d, vis)) {
            return false;
        }
    }
    return true;
}

void move(std::vector<std::string>& G, std::vector<std::array<int, 3>>& vis, int d) {
    std::set<std::pair<int, int>> s;
    for(auto& a : vis) {
        int r = a[0];
        int c = a[1];
        int nr = r + DR[d];
        int nc = c + DC[d];
        s.emplace(nr, nc);
    }

    for(auto& a : vis) {
        int r = a[0];
        int c = a[1];
        int t = a[2];
        int nr = r + DR[d];
        int nc = c + DC[d];
        if(t == 0) {
            G[nr][nc] = '[';
        } else {
            G[nr][nc] = ']';
        }
        if(s.find({r, c}) == s.end()) {
            G[r][c] = '.';
        }
    }
}

void run_case() {
    std::vector<std::string> G;
    std::string A = "";
    std::string M = ">v<^";
    
    bool reading_seq = false;
    for(std::string S; std::getline(std::cin, S); ) {
        if(S.empty()) {
            reading_seq = true;
            continue;
        }

        if(reading_seq) {
            A.append(S);
        } else {
            std::string s = "";
            int size = S.size();
            for(int i = 0; i < size; i++) {
                if(S[i] == '#') {
                    s.append("##");
                } else if(S[i] == '.') {
                    s.append("..");
                } else if(S[i] == 'O') {
                    s.append("[]");
                } else {
                    s.append("@.");
                }
            }
            G.push_back(s);
        }
    }

    int n = G.size();
    int m = G[0].size();
    int q = A.size();
    int r = -1;
    int c = -1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == '@') {
                r = i;
                c = j;
                G[i][j] = '.';
            }
        }
    }

    for(int i = 0; i < q; i++) {
        int d = M.find(A[i]);
        int nr = r + DR[d];
        int nc = c + DC[d];

        if(G[nr][nc] == '#') {
            continue;
        }
        if(G[nr][nc] == '.') {
            r = nr;
            c = nc;
            continue;
        }

        std::vector<std::array<int, 3>> vis;
        if(d == 1 || d == 3) {
            bool lhs;
            bool rhs;
            if(G[nr][nc] == '[') {
                lhs = dfs(G, nr, nc, d, vis);  
                rhs = dfs(G, nr, nc + 1, d, vis);
                if(lhs && rhs) {
                    move(G, vis, d);
                    r = nr;
                    c = nc;
                }
            } else {
                lhs = dfs(G, nr, nc, d, vis);  
                rhs = dfs(G, nr, nc - 1, d, vis);
                if(lhs && rhs) {
                    move(G, vis, d);
                    r = nr;
                    c = nc;
                }
            }
        } else {
            if(dfs(G, nr, nc, d, vis)) {
                move(G, vis, d);
                r = nr;
                c = nc;
            }
        }
    } 

    
    int64_t ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == '[') {
                ans += i * 100 + j;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        std::cout << G[i] << '\n';
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
