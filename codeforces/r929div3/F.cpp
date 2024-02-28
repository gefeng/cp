#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> G(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> G[i][j];
        }
    }

    std::vector<int> cur(N, -1);
    cur[0] = 0;
    
    for(int i = 0; i < M - 1; i++) {
        std::vector<int> nxt(N, -1);
        std::vector<int> vis(N, 0);
        int r = 0;
        while(!vis[r]) {
            if(cur[r] == -1) {
                vis[r] = 1;
            } else {
                int t = cur[r];
                while(true) {
                    vis[r] = 1;
                    int nr = (r + 1 + t) % N;
                    if(G[nr][i + 1] == 0) {
                        nxt[r] = nxt[r] == -1 ? t + 1 : std::min(nxt[r], t + 1);
                    }
                    
                    if(G[(r + 1 + t) % N][i] == 0 && G[(r + 2 + t) % N][i] == 0 && (cur[(r + 1) % N] == -1 || cur[(r + 1) % N] > t + 1)) {
                        r += 1;
                        r %= N;
                        t += 1;
                    } else {
                        break;
                    }
                }
            }
            r = (r + 1) % N;
        }

        std::swap(cur, nxt);
    }

    int ans = -1;
    for(int i = 0; i < N; i++) {
        if(cur[i] != -1) {
            int d = std::min(N - 1 - i, i + 1);
            d += cur[i];
            ans = ans == -1 ? d : std::min(ans, d); 
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
