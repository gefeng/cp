#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, W, K;
    std::cin >> H >> W >> K;
    
    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    std::vector<std::vector<int>> psum(H + 1, std::vector<int>(W + 1, 0)); 
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + G[i - 1][j - 1] - '0';
        }
    }

    int ans = H * W;
    int n = 1 << H;
    for(int i = 0; i < n; i++) {
        int pre_c = -1;
        bool ok = true;
        int cnt = __builtin_popcount(i) - 1;
        if((i & (1 << (H - 1))) == 0) {
            continue;
        }

        for(int j = 0; j < W; j++) {
            bool can_cut = true;

            int pre_r = -1;
            for(int k = 0; k < H; k++) {
                if(i & (1 << k)) {
                    int r = k; 
                    int c = j;
                    
                    int tot = psum[r + 1][c + 1] - psum[pre_r + 1][c + 1] - psum[r + 1][pre_c + 1] + psum[pre_r + 1][pre_c + 1];
                    if(tot > K) {
                        can_cut = false;
                        break;
                    }

                    pre_r = r;
                } 
            }
            
            if(!can_cut) {
                if(j - pre_c == 1) {
                    ok = false;
                    break;
                }

                cnt += 1;

                pre_c = j - 1; 
                j -= 1;
            } 
        }

        if(ok) {
            ans = std::min(ans, cnt);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
