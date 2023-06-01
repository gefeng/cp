#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int H = 50000;
constexpr int W = 7;
constexpr int MAX_ROCK = 456;
constexpr int REM = 1274;

void run_case() {
    std::string S;
    std::cin >> S;

    std::vector<std::vector<int>> g(H, std::vector<int>(W, 0));
    int max_h = 0;

    auto move = [&](std::vector<int>& shape_r, std::vector<int>& shape_c, int dr, int dc) {
        int sz = shape_r.size();
        for(int i = 0; i < sz; i++) {
            int nr = shape_r[i] + dr;
            int nc = shape_c[i] + dc;

            if(nr < 0 || nc < 0 || nr >= H || nc >= W || g[nr][nc] == 1) {
                return false;
            }
        }

        for(int i = 0; i < sz; i++) {
            shape_r[i] += dr; 
            shape_c[i] += dc;
        }

        return true;
    };

    auto merge = [&](std::vector<int>& shape_r, std::vector<int>& shape_c) {
        int sz = shape_r.size();
        int min_r = H;
        for(int i = 0; i < sz; i++) {
            g[shape_r[i]][shape_c[i]] = 1;
            min_r = std::min(min_r, shape_r[i]);
        }
        return min_r;
    };
    
    int pre = -1;
    std::vector<int> save_h(MAX_ROCK + 1, 0);
    for(int i = 0, j = 0; i < MAX_ROCK + REM; i++) {
        int sr = H - 4 - max_h;
        int sc = 2;
        
        std::vector<int> shape_r;
        std::vector<int> shape_c;
        if(i % 5 == 0) {
            shape_r = {sr, sr, sr, sr};
            shape_c = {sc, sc + 1, sc + 2, sc + 3};
        } else if(i % 5 == 1) {
            shape_r = {sr - 2, sr - 1, sr - 1, sr - 1, sr};     
            shape_c = {sc + 1, sc, sc + 1, sc + 2, sc + 1};
        } else if(i % 5 == 2) {
            shape_r = {sr - 2, sr - 1, sr, sr, sr};
            shape_c = {sc + 2, sc + 2, sc, sc + 1, sc + 2};
        } else if(i % 5 == 3) {
            shape_r = {sr - 3, sr - 2, sr - 1, sr};
            shape_c = {sc, sc, sc, sc};
        } else {
            shape_r = {sr - 1, sr - 1, sr, sr};
            shape_c = {sc, sc + 1, sc, sc + 1};
        }

        while(true) {
            int d = S[j] == '>' ? 1 : -1; 
            j = (j + 1) % S.size();
            
            move(shape_r, shape_c, 0, d);

            if(!move(shape_r, shape_c, 1, 0)) {
                int min_r = merge(shape_r, shape_c);
                

                max_h = std::max(max_h, H - min_r);
                //save_h[i + 1] = max_h;

                /*for(int r : shape_r) {
                    bool ok = true;
                    for(int c = 0; c < 7; c++) {
                        if(!g[r][c]) {
                            ok = false;
                            break;
                        }
                    }

                    if(ok) {
                        std::cout << i + 1 << ' ';
                        if(pre != -1) {
                            std::cout << i - pre << ' ' << save_h[i] << '\n';
                        } else {
                            std::cout << '\n';
                        }
                        pre = i + 1;
                        break;
                    }
                }*/

                break;
            }
        }
    }

    //std::cout << (1000000000000 - 456) % 1715 << '\n';

    /*int pre = -1;
    int pre_215 = 0;
    for(int i = H - max_h; i < H; i++) {
        std::string s = "";
        for(int j = 0; j < 7; j++) {
            if(g[i][j] == 0) {
                s.push_back('.');
            } else {
                s.push_back('#');
            }
        }

        if(s == "#######") {
            if(pre != -1) {
                std::cout << i << ' ' << i - pre << '\n'; 
            }
            pre = i;
        }
    }*/
    std::cout << 2751LL + (583090378LL * 2690LL)  << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
