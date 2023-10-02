#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<std::string> A(4);
    std::vector<std::string> B(4);
    std::vector<std::string> C(4);
    for(int i = 0; i < 4; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < 4; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < 4; i++) {
        std::cin >> C[i];
    }

    auto rotate = [](std::vector<std::string> g, int times) {
        std::vector<std::string> cur(g);
        while(times--) {
            std::vector<std::string> nxt(g);
            for(int i = 0; i < 4; i++) {
                for(int j = 0; j < 4; j++) {
                    nxt[j][3 - i] = cur[i][j];
                }
            }
            std::swap(nxt, cur);
        }
        return cur;
    };

    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            for(int k = 0; k < 16; k++) {
                for(int r1 = 0; r1 < 4; r1++) {
                    for(int r2 = 0; r2 < 4; r2++) {
                        for(int r3 = 0; r3 < 4; r3++) {
                            int x1 = i / 4;
                            int y1 = i % 4;
                            int x2 = j / 4;
                            int y2 = j % 4;
                            int x3 = k / 4;
                            int y3 = k % 4;
                        
                            std::vector<std::string> g1 = rotate(A, r1);
                            std::vector<std::string> g2 = rotate(B, r2);
                            std::vector<std::string> g3 = rotate(C, r3);

                            std::vector<std::vector<int>> g(4, std::vector<int>(4, 0));
                            int dr = -100;
                            int dc = -100;
                            bool ok = true;
                            int cnt = 0;
                            for(int r = 0; r < 4; r++) {
                                for(int c = 0; c < 4; c++) {
                                    if(g1[r][c] == '#') {
                                        if(dr == -100) {
                                            dr = x1 - r;
                                            dc = y1 - c;
                                        } 

                                        int nr = r + dr;
                                        int nc = c + dc;
                                        if(nr >= 0 && nc >= 0 && nr < 4 && nc < 4 && g[nr][nc] == 0) {
                                            g[nr][nc] = 1;
                                            cnt += 1;
                                        } else {
                                            ok = false;
                                        }
                                    } 
                                }
                            }

                            dr = -100;
                            dc = -100;
                            for(int r = 0; r < 4; r++) {
                                for(int c = 0; c < 4; c++) {
                                    if(g2[r][c] == '#') {
                                        if(dr == -100) {
                                            dr = x2 - r;
                                            dc = y2 - c;
                                        } 

                                        int nr = r + dr;
                                        int nc = c + dc;
                                        if(nr >= 0 && nc >= 0 && nr < 4 && nc < 4 && g[nr][nc] == 0) {
                                            g[nr][nc] = 1;
                                            cnt += 1;
                                        } else {
                                            ok = false;
                                        }
                                    } 
                                }
                            }

                            dr = -100;
                            dc = -100;
                            for(int r = 0; r < 4; r++) {
                                for(int c = 0; c < 4; c++) {
                                    if(g3[r][c] == '#') {
                                        if(dr == -100) {
                                            dr = x3 - r;
                                            dc = y3 - c;
                                        } 

                                        int nr = r + dr;
                                        int nc = c + dc;
                                        if(nr >= 0 && nc >= 0 && nr < 4 && nc < 4 && g[nr][nc] == 0) {
                                            g[nr][nc] = 1;
                                            cnt += 1;
                                        } else {
                                            ok = false;
                                        }
                                    } 
                                }
                            }

                            if(ok && cnt == 16) {
                                std::cout << "Yes" << '\n';
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
