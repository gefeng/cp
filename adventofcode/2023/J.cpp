#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int INF = (int)1e9;

std::map<char, std::array<int, 2>> MX = {{'|', {-1, 1}}, {'-', {0, 0}}, {'L', {-1, 0}}, {'J', {-1, 0}}, {'7', {1, 0}}, {'F', {1, 0}}};
std::map<char, std::array<int, 2>> MY = {{'|', {0, 0}}, {'-', {-1, 1}}, {'L', {0, 1}}, {'J', {0, -1}}, {'7', {0, -1}}, {'F', {0, 1}}};

std::array<int, 4> DR = {-1, 0, 1, 0};
std::array<int, 4> DC = {0, 1, 0, -1};

std::vector<std::string> G;

std::array<int, 2> joint(int r, int c) {
    std::array<int, 2> a;
    char x = G[r][c];
    if(x == '|') {
        a = {0, 2};
    } else if(x == '-') {
        a = {1, 3};
    } else if(x == 'L') {
        a = {0, 1};
    } else if(x == 'J') {
        a = {0, 3};
    } else if(x == '7') {
        a = {2, 3};
    } else {
        a = {1, 2};
    }
    return a;
}

void dfs(int n, int m, std::vector<std::vector<int>>& g, std::vector<std::vector<int>>& vis, int r, int c, std::vector<std::pair<int, int>>& a) {
    vis[r][c] = 1;
    a.emplace_back(r, c);
    
    for(int d = 0; d < 4; d++) {
        int nr = r + DR[d]; 
        int nc = c + DC[d];
        if(nr >= 0 && nc >= 0 && nr < n * 3 && nc < m * 3 && !vis[nr][nc] && g[nr][nc] != 1) {
            dfs(n, m, g, vis, nr, nc, a);
        }
    }
}

void run_case1() {
    int n = G.size();
    int m = G[0].size();
    
    int sr = -1;
    int sc = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == 'S') {
                sr = i;
                sc = j;
            }
        }
    }

    std::vector<std::vector<int>> dist(n, std::vector<int>(m, INF));
    
    auto go = [&](int dir) {
        std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
        int r = sr;
        int c = sc;
        int d = 0;
        while(!vis[r][c]) {
            vis[r][c] = 1;
            dist[r][c] = std::min(dist[r][c], d++);

            r += DR[dir];
            c += DC[dir]; 
            
            std::array<int, 2> a = joint(r, c);
            int ndir = -1;
            for(int i = 0; i < 2; i++) {
                int odr = DR[a[i]];
                int odc = DC[a[i]];
                odr = odr == 0 ? 0 : -odr;
                odc = odc == 0 ? 0 : -odc;
                
                if(odr == DR[dir] && odc == DC[dir]) {
                    ndir = a[i ^ 1];
                    break;
                }
            }

            dir = ndir;
        }
    }; 

    go(0);
    go(1);
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dist[i][j] != INF) {
                ans = std::max(ans, dist[i][j]);
            }
        }
    }

    std::cout << ans << '\n';
}

void run_case2() {
    int ans = 0;
    int n = G.size();
    int m = G[0].size();
    
    int sr = -1;
    int sc = -1;
    std::vector<std::vector<int>> g(n * 3, std::vector<int>(m * 3, 0));
    std::vector<std::vector<int>> loop(n, std::vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == 'S') {
                sr = i;
                sc = j;
            }
        }
    }

    auto is_valid = [&](int r, int c) {
        return r >= 0 && c >= 0 && r < n && c < m;
    };

    auto paint_loop = [&](int r, int c) {
        if(G[r][c] == '|') {
            g[r * 3][c * 3 + 1] = 1;
            g[r * 3 + 1][c * 3 + 1] = 1;
            g[r * 3 + 2][c * 3 + 1] = 1;
        } else if(G[r][c] == '-') {
            g[r * 3 + 1][c * 3] = 1;
            g[r * 3 + 1][c * 3 + 1] = 1;
            g[r * 3 + 1][c * 3 + 2] = 1;
        } else if(G[r][c] == 'L') {
            g[r * 3][c * 3 + 1] = 1;
            g[r * 3 + 1][c * 3 + 1] = 1;
            g[r * 3 + 1][c * 3 + 2] = 1; 
        } else if(G[r][c] == 'J') {
            g[r * 3][c * 3 + 1] = 1;
            g[r * 3 + 1][c * 3 + 1] = 1;
            g[r * 3 + 1][c * 3] = 1;
        } else if(G[r][c] == '7') {
            g[r * 3 + 1][c * 3] = 1;
            g[r * 3 + 1][c * 3 + 1] = 1;
            g[r * 3 + 2][c * 3 + 1] = 1;
        } else if(G[r][c] == 'F') {
            g[r * 3 + 1][c * 3 + 2] = 1;
            g[r * 3 + 1][c * 3 + 1] = 1;
            g[r * 3 + 2][c * 3 + 1] = 1;
        }
    };

    auto paint_nonloop = [&](int r, int c) {
        g[r * 3 + 1][c * 3 + 1] = 2;
    };

    auto go = [&](int dir) {
        int r = sr;
        int c = sc;
        while(!loop[r][c]) {
            loop[r][c] = 1;
            
            paint_loop(r, c);

            r += DR[dir];
            c += DC[dir]; 
            
            std::array<int, 2> a = joint(r, c);
            int ndir = -1;
            for(int i = 0; i < 2; i++) {
                int odr = DR[a[i]];
                int odc = DC[a[i]];
                odr = odr == 0 ? 0 : -odr;
                odc = odc == 0 ? 0 : -odc;
                
                if(odr == DR[dir] && odc == DC[dir]) {
                    ndir = a[i ^ 1];
                    break;
                }
            }

            dir = ndir;
        }
    }; 

    go(1);

    for(int d1 = 0; d1 < 4; d1++) {
        for(int d2 = 0; d2 < 4; d2++) {
            if(d1 == d2) {
                continue;
            }
            int nr1 = sr + DR[d1];
            int nc1 = sc + DC[d1];
            int nr2 = sr + DR[d2];
            int nc2 = sc + DC[d2];
            if(is_valid(nr1, nc1) && is_valid(nr2, nc2)) {
                if(loop[nr1][nc1] && loop[nr2][nc2]) {
                    if(d1 == 0 && d2 == 1) {
                        G[sr][sc] = 'L';
                    } else if(d1 == 0 && d2 == 2) {
                        G[sr][sc] = '|';
                    } else if(d1 == 0 && d2 == 3) {
                        G[sr][sc] = 'J';
                    } else if(d1 == 1 && d2 == 2) {
                        G[sr][sc] = 'F';
                    } else if(d1 == 1 && d2 == 3) {
                        G[sr][sc] = '-';
                    } else {
                        G[sr][sc] = '7';
                    }
                    paint_loop(sr, sc);
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!loop[i][j]) {
                paint_nonloop(i, j); 
            }
        }
    }


    std::vector<std::vector<int>> vis(n * 3, std::vector<int>(m * 3, 0));
    for(int i = 0; i < n * 3; i++) {
        for(int j = 0; j < m * 3; j++) {
            if(vis[i][j] || g[i][j] == 1) {
                continue;
            }

            std::vector<std::pair<int, int>> a;
            dfs(n, m, g, vis, i, j, a); 

            //std::cout << a.size() << '\n';

            bool outside = false;
            int cnt = 0;
            for(auto [r, c] : a) {
                if(r == 0 || c == 0 || r == n * 3 - 1 || c == m * 3 - 1) {
                    outside = true;
                }
                if(g[r][c] == 2) {
                    cnt += 1;
                }
            }

            if(!outside) {
                ans += cnt;
            }
        }
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

    //run_case1();
    run_case2();
}
