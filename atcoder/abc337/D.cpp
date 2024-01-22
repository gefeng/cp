#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

void run_case() {
    int H, W, K;
    std::cin >> H >> W >> K;

    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    int ans = INF;
    for(int i = 0; i < H; i++) {
        int cnt_x = 0;
        int cnt_o = 0;
        for(int l = 0, r = 0; r < W; r++) {
            if(G[i][r] == 'o') {
                cnt_o += 1;
            } else if(G[i][r] == 'x') {
                cnt_x += 1;
            }

            if(r - l + 1 > K) {
                if(G[i][l] == 'o') {
                    cnt_o -= 1;
                } else if(G[i][l] == 'x') {
                    cnt_x -= 1;
                }
                l += 1;
            }

            if(r - l + 1 == K) {
                if(cnt_x == 0) {
                    ans = std::min(ans, K - cnt_o);
                }
            }
        }
    }

    for(int i = 0; i < W; i++) {
        int cnt_x = 0;
        int cnt_o = 0;
        for(int l = 0, r = 0; r < H; r++) {
            if(G[r][i] == 'o') {
                cnt_o += 1;
            } else if(G[r][i] == 'x') {
                cnt_x += 1;
            }

            if(r - l + 1 > K) {
                if(G[l][i] == 'o') {
                    cnt_o -= 1;
                } else if(G[l][i] == 'x') {
                    cnt_x -= 1;
                }
                l += 1;
            }

            if(r - l + 1 == K) {
                if(cnt_x == 0) {
                    ans = std::min(ans, K - cnt_o);
                }
            }
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
