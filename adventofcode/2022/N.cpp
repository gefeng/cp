#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int H = 600;
constexpr int W = 600;
constexpr int offset = 500;

void run_case() {
    std::vector<std::string> G(H);

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W + offset * 2; j++) {
            G[i].push_back('.');
        }
    }

    auto is_digit = [](char c) {
        return c >= '0' && c <= '9';
    };

    std::string S;
    int max_h = 0;
    while(std::getline(std::cin, S)) {
        int n = S.size();
        std::vector<std::pair<int, int>> rock;
        
        int r = -1;
        int c = -1;
        for(int i = 0; i < n; ) {
            if(is_digit(S[i])) {
                int x = 0;
                while(i < n && is_digit(S[i])) {
                    x = x * 10 + S[i] - '0';
                    i += 1;
                }

                if(c == -1) {
                    c = x;
                } else {
                    r = x;            
                    max_h = std::max(max_h, r);
                    rock.emplace_back(r, c + offset);
                    r = -1;
                    c = -1;
                }
            } else {
                i += 1;
            }
        }

        int sz = rock.size();
        for(int i = 1; i < sz; i++) {
            if(rock[i].first != rock[i - 1].first) {
                int l = std::min(rock[i].first, rock[i - 1].first);
                int r = std::max(rock[i].first, rock[i - 1].first);

                for(int k = l; k <= r; k++) {
                    G[k][rock[i].second] = '#';
                }
            } else {
                int l = std::min(rock[i].second, rock[i - 1].second);
                int r = std::max(rock[i].second, rock[i - 1].second);
                
                for(int k = l; k <= r; k++) {
                    G[rock[i].first][k] = '#';
                }
            }
        }
    }

    int ans = 0;
    int b_r = max_h + 2;
    
    for(int i = 0; i < W + offset * 2; i++) {
        G[b_r][i] = '#';
    }

    while(true) {
        int r = 0;
        int c = 500 + offset;
        
        bool full = false;
        while(true) {
            int nr = r + 1;
            if(G[nr][c] == '.') {
                r = nr;
                continue;
            }

            int nc = c - 1;
            /*if(nc < 0) {
                full = true;
                break;
            }*/

            if(G[nr][nc] == '.') {
                r = nr;
                c = nc;
                continue;
            }

            nc = c + 1;
            /*if(nc >= W) {
                full = true;
                break;
            }*/

            if(G[nr][nc] == '.') {
                r = nr;
                c = nc;
                continue;
            }

            ans += 1;
            G[r][c] = 'o';
            break;
        }

        if(G[0][500 + offset] == 'o') {
            break;
        }
    }

    /*for(int i = 0; i < H; i++) {
        std::cout << G[i] << '\n';
    }*/

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
