#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>

const std::array<int, 5> DR = {0, 1, 0, -1, 0};
const std::array<int, 5> DC = {1, 0, -1, 0, 0};

void run_case() {
    std::vector<std::vector<int>> G;

    std::string S;
    while(std::getline(std::cin, S)) {
        int sz = S.size();

        G.emplace_back();
        for(int i = 0; i < sz; i++) {
            if(S[i] == '#') {
                G.back().push_back(-1); 
            } else if(S[i] == '.') {
                G.back().push_back(0);
            } else {
                if(S[i] == '>') {
                    G.back().push_back(1);
                } else if(S[i] == 'v') {
                    G.back().push_back(2);
                } else if(S[i] == '<') {
                    G.back().push_back(4);
                } else if(S[i] == '^') {
                    G.back().push_back(8);
                }
            }
        }
    }

    int N = G.size();
    int M = G[0].size();

    auto move = [&]() {
        std::vector<std::vector<int>> ng(N, std::vector<int>(M, 0));

        for(int r = 0; r < N; r++) {
            for(int c = 0; c < M; c++) {
                if(G[r][c] == -1 || G[r][c] == 0) {
                    ng[r][c] = G[r][c];
                }
            }
        }
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < M; c++) {
                if(G[r][c] > 0) {
                    for(int i = 0; i < 4; i++) {
                        if(G[r][c] & (1 << i)) {
                            int nr = r + DR[i];
                            int nc = c + DC[i];
                            if(nr >= N - 1 || nr < 1 || nc >= M - 1 || nc < 1) {
                                if(i == 0) {
                                    nc = 1;
                                } else if(i == 1) {
                                    nr = 1;
                                } else if(i == 2) {
                                    nc = M - 2;
                                } else {
                                    nr = N - 2;
                                }
                            }
                            ng[nr][nc] |= 1 << i;
                        }
                    }
                }
            } 
        }

        std::swap(G, ng);
        /*std::cout << "**************************************" << '\n';
        for(int r = 0; r < N; r++) {
            std::string s;
            for(int c = 0; c < M; c++) {
                if(G[r][c] == 0) {
                    s.push_back('.');
                } else if(G[r][c] == -1) {
                    s.push_back('#');
                } else {
                    int x = G[r][c];
                    if(x == 1) {
                        s.push_back('>');
                    } else if(x == 2) {
                        s.push_back('v');
                    } else if(x == 4) {
                        s.push_back('<');
                    } else if(x == 8) {
                        s.push_back('^');
                    } else {
                        s.push_back((char)(__builtin_popcount(x) + '0'));
                    }
                }
            }

            std::cout << s << '\n';
        }*/
    };

    std::vector<std::vector<std::vector<int>>> save_g;
    std::set<std::vector<std::vector<int>>> seen;
    while(true) {
        if(seen.find(G) != seen.end()) {
            break;
        } 

        seen.insert(G);
        save_g.push_back(G);
        move(); 
    }
    
    int n = save_g.size();
    int sr = 0;
    int sc = 1;
    int tr = N - 1; 
    int tc = M - 2;
    std::queue<std::array<int, 2>> q;
    q.push({sr, sc});
    std::vector<std::vector<std::vector<bool>>> vis(N, std::vector<std::vector<bool>>(M, std::vector<bool>(n, false)));
    
    int ans = 0;
    int j = 0;
    std::vector<std::vector<int>> now;
    int cnt = 0;
    while(!q.empty()) {
        int sz = q.size(); 

        move();
        j = (j + 1) % n;
        now = save_g[j];

        while(sz--) {
            std::array<int, 2> cur = q.front();
            q.pop();

            int r = cur[0];
            int c = cur[1];

            if(cnt == 0 && r == tr && c == tc) {
                cnt += 1;
                vis = std::vector<std::vector<std::vector<bool>>>(N, std::vector<std::vector<bool>>(M, std::vector<bool>(n, false)));
                q = std::queue<std::array<int, 2>>();

                q.push({tr, tc});
                vis[tr][tc][j] = true;

                break;
            }
            if(cnt == 1 && r == sr && c == sc) {
                cnt += 1;
                vis = std::vector<std::vector<std::vector<bool>>>(N, std::vector<std::vector<bool>>(M, std::vector<bool>(n, false)));
                q = std::queue<std::array<int, 2>>();

                q.push({sr, sc});
                vis[sr][sc][j] = true;

                break;
            }
            if(cnt == 2 && r == tr && c == tc) {
                std::cout << ans << '\n';
                return;
            }

            for(int i = 0; i < 5; i++) {
                int nr = r + DR[i]; 
                int nc = c + DC[i];
                if(nr >= 0 && nc >= 0 && nr < N && nc < M && G[nr][nc] == 0 && !vis[nr][nc][j]) {
                    q.push({nr, nc});
                    vis[nr][nc][j] = true; 
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
