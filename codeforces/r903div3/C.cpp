#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::string> G(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::array<char, 4> a = {G[i][j], G[j][N - i - 1], G[N - i - 1][N - j - 1], G[N - j - 1][i]};
            G[i][j] = '.';
            G[j][N - i - 1] = '.'; 
            G[N - i - 1][N - j - 1] = '.';
            G[N - j - 1][i] = '.';

            bool vis = false;
            for(int k = 0; k < 4; k++) {
                if(a[k] == '.') {
                    vis = true;
                    break;
                }
            }

            if(vis) {
                continue;
            }

            int min_v = INF;
            for(char c = 'a'; c <= 'z'; c++) {
                int cnt = 0;
                for(int k = 0; k < 4; k++) {
                    if(a[k] > c) {
                        cnt = -1;
                        break;
                    } 
                    cnt += c - a[k];
                }

                if(cnt != -1) {
                    min_v = std::min(min_v, cnt);
                }
            }
            
            if(min_v != INF) {
                ans += min_v;
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
