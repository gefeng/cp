#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    std::vector<std::vector<int>> cnt_row(H, std::vector<int>(26, 0));
    std::vector<std::vector<int>> cnt_col(W, std::vector<int>(26, 0));
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cnt_row[i][G[i][j] - 'a'] += 1;
            cnt_col[j][G[i][j] - 'a'] += 1;
        }
    }
    
    while(true) {
        std::vector<int> remove_row;
        std::vector<int> remove_col;
        for(int r = 0; r < H; r++) {
            int cnt = 0;
            for(int i = 0; i < 26; i++) { 
                if(cnt_row[r][i]) {
                    cnt += 1;
                }
            } 

            if(cnt == 1) {
                for(int i = 0; i < 26; i++) {
                    if(cnt_row[r][i] > 1) {
                        remove_row.push_back(r);
                    }
                }
            }
        }

        for(int c = 0; c < W; c++) {
            int cnt = 0;
            for(int i = 0; i < 26; i++) {
                if(cnt_col[c][i]) {
                    cnt += 1;
                }
            }

            if(cnt == 1) {
                for(int i = 0; i < 26; i++) {
                    if(cnt_col[c][i] > 1) {
                        remove_col.push_back(c);
                    }
                }
            }
        }

        if(remove_row.empty() && remove_col.empty()) {
            break;
        }

        for(int r : remove_row) {
            int ch = 0;
            for(int i = 0; i < 26; i++) {
                if(cnt_row[r][i]) {
                    cnt_row[r][i] = 0;
                    ch = i;
                }
            }

            for(int c = 0; c < W; c++) {
                cnt_col[c][ch] = std::max(0, cnt_col[c][ch] - 1);
            }
        }

        for(int c : remove_col) {
            int ch = 0;
            for(int i = 0; i < 26; i++) {
                if(cnt_col[c][i]) {
                    cnt_col[c][i] = 0;
                    ch = i;
                }
            }

            for(int r = 0; r < H; r++) {
                cnt_row[r][ch] = std::max(0, cnt_row[r][ch] - 1);
            }
        }
    }

    int ans = 0;
    for(int r = 0; r < H; r++) {
        for(int i = 0; i < 26; i++) {
            ans += cnt_row[r][i];
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
