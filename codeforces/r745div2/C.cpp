#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }

    std::vector<std::vector<int>> psum(N + 1, std::vector<int>(M + 1, 0));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + (G[i - 1][j - 1] - '0');
        } 
    }

    int ans = N * M;
    for(int c1 = 0; c1 < M; c1++) {
        for(int c2 = c1 + 3; c2 < M; c2++) {
            int pre = N * M;
            for(int r = 4; r < N; r++) {
                int cnt = psum[r][c2] - psum[r - 3][c2] - psum[r][c1 + 1] + psum[r - 3][c1 + 1];
                cnt += c2 - c1 + 1 - 2 - (psum[r + 1][c2] - psum[r][c2] - psum[r + 1][c1 + 1] + psum[r][c1 + 1]);
                cnt += c2 - c1 + 1 - 2 - (psum[r - 3][c2] - psum[r - 4][c2] - psum[r - 3][c1 + 1] + psum[r - 4][c1 + 1]);
                cnt += 3 - (psum[r][c1 + 1] - psum[r - 3][c1 + 1] - psum[r][c1] + psum[r - 3][c1]);
                cnt += 3 - (psum[r][c2 + 1] - psum[r - 3][c2 + 1] - psum[r][c2] + psum[r - 3][c2]);

                ans = std::min(ans, cnt);
                 
                if(r > 4) {
                    int now = cnt;
                    cnt = pre; 
                    cnt -= c2 - c1 + 1 - 2 - (psum[r][c2] - psum[r - 1][c2] - psum[r][c1 + 1] + psum[r - 1][c1 + 1]);
                    cnt += psum[r][c2] - psum[r - 1][c2] - psum[r][c1 + 1] + psum[r - 1][c1 + 1];
                    cnt += c2 - c1 + 1 - 2 - (psum[r + 1][c2] - psum[r][c2] - psum[r + 1][c1 + 1] + psum[r][c1 + 1]);
                    if(G[r - 1][c1] == '0') {
                        cnt += 1;
                    }
                    if(G[r - 1][c2] == '0') {
                        cnt += 1;
                    }

                    ans = std::min(ans, cnt);
                    pre = std::min(cnt, now);
                } else {
                    pre = cnt;
                }
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
