#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

const std::array<int, 8> DR = {-1, -1, 0, 1, 1, 1, 0, -1};
const std::array<int, 8> DC = {0, 1, 1, 1, 0, -1, -1, -1};
const std::array<int, 4> DD = {0, 4, 6, 2};

const int PADDING = 200;

void run_case() {
    std::vector<std::string> G;

    for(int i = 0; i < PADDING; i++) {
        G.emplace_back();
    }

    std::string S;
    int M, N;
    while(std::getline(std::cin, S)) {
        G.emplace_back();
        for(int i = 0; i < PADDING; i++) {
            G.back().push_back('.');
        }
        G.back().append(S);
        for(int i = 0; i < PADDING; i++) {
            G.back().push_back('.');
        }
        M = G.back().size();
    }
    
    for(int i = 0; i < PADDING; i++) {
        for(int j = 0; j < M; j++) {
            G[i].push_back('.'); 
        }
    }
    
    for(int i = 0; i < PADDING; i++) {
        G.emplace_back();
        
        for(int j = 0; j < M; j++) {
            G.back().push_back('.');
        }
    }

    N = G.size();

    std::vector<std::string> g(G);
    std::vector<std::vector<int>> dir(N, std::vector<int>(M, 0));

    int round;
    for(round = 0; ; round += 1) {
        std::vector<std::vector<int>> propose(N, std::vector<int>(M, -1));
        
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < M; c++) {
                if(g[r][c] == '#') {
                    bool action = false;
                    
                    for(int d = 0; d < 8; d++) {
                        int nr = r + DR[d];
                        int nc = c + DC[d];
                        if(nr >= 0 && nc >= 0 && nr < N && nc < M && g[nr][nc] == '#') {
                            action = true;
                            break;
                        }
                    }

                    if(action) {
                        int move = -1;

                        int st = dir[r][c];
                        for(int j = 0, d = st; j < 4; j++, d = (d + 1) % 4) {
                            int cnt = 0;
                            for(int k = -1; k < 2; k++) {
                                int dd = (DD[d] + k + 8) % 8;
                                int nr = r + DR[dd];
                                int nc = c + DC[dd];

                                if(nr >= 0 && nc >= 0 && nr < N && nc < M) {
                                    if(g[nr][nc] == '.') {
                                        cnt += 1;
                                    }
                                }
                            }

                            if(cnt == 3) {
                                move = DD[d];
                                break;
                            }
                        }

                        if(move != -1) {
                            int nr = r + DR[move];
                            int nc = c + DC[move];
                            if(propose[nr][nc] == -1) {
                                propose[nr][nc] = r * M + c;
                            } else if(propose[nr][nc] >= 0) {
                                propose[nr][nc] = -2; 
                            }
                        }

                    }
                    dir[r][c] = (dir[r][c] + 1) % 4;
                }
            }
        }

        bool end = true;
        for(int r = 0; r < N; r++) {
            for(int c = 0; c < M; c++) {
                int x = propose[r][c];
                
                if(x >= 0) {
                    g[r][c] = '#';
                    g[x / M][x % M] = '.';
                    dir[r][c] = dir[x / M][x % M];
                    end = false;
                }
            }
        }

        if(end) {
            break;
        }

        /*std::cout << "Round " << i + 1 << '\n';
        for(int r = 0; r < N; r++) {
            std::cout << g[r] << '\n';
        }
        std::cout << '\n';*/
    }

    std::cout << round + 1 << '\n';

    /*int min_r = N;
    int max_r = 0;
    int min_c = M;
    int max_c = 0;
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            if(g[r][c] == '#') {
                min_r = std::min(min_r, r);
                max_r = std::max(max_r, r);
                min_c = std::min(min_c, c);
                max_c = std::max(max_c, c);
            }
        }
    }

    int ans = 0;
    for(int r = min_r; r <= max_r; r++) {
        for(int c = min_c; c <= max_c; c++) {
            if(g[r][c] == '.') {
                ans += 1;
            }
        }
    }

    std::cout << ans << '\n';*/
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
