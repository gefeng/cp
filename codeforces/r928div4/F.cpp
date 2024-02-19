#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {1, 1, -1, -1};
constexpr std::array<int, 4> DC = {1, -1, 1, -1};
constexpr int MAX = 49;

std::vector<int> masks;

void run_case() {
    std::vector<std::string> G(7);
    for(int i = 0; i < 7; i++) {
        std::cin >> G[i];
    }

    int ans = 0;
    for(int t = 0; t < 2; t++) {
        int min_v = MAX;
        for(int m : masks) {
            int flip = 0;
            int p = 0;
            for(int r = 0; r < 7; r++) {
                for(int c = (r % 2 == t ? 0 : 1); c < 7; c += 2) {
                    if(m & (1 << p)) {
                        G[r][c] = G[r][c] == 'W' ? 'B' : 'W';
                        flip += 1;
                    } 
                    p += 1;
                }
            }

            bool ok = true;
            for(int r = 0; r < 7; r++) {
                for(int c = (r % 2 == t ? 0 : 1); c < 7; c += 2) {
                    if(G[r][c] == 'B') {
                        int cnt = 0;
                        for(int d = 0; d < 4; d++) {
                            int nr = r + DR[d];
                            int nc = c + DC[d];
                            if(nr >= 0 && nc >= 0 && nr < 7 && nc < 7 && G[nr][nc] == 'B') {
                                cnt += 1;
                            } 
                        }

                        if(cnt == 4) {
                            ok = false;
                            break;
                        }
                    }
                }

                if(!ok) {
                    break;
                }
            }

            if(ok) {
                min_v = std::min(min_v, flip);
            }

            p = 0;
            for(int r = 0; r < 7; r++) {
                for(int c = (r % 2 == t ? 0 : 1); c < 7; c += 2) {
                    if(m & (1 << p)) {
                        G[r][c] = G[r][c] == 'W' ? 'B' : 'W';
                    } 
                    p += 1;
                }
            }
        }
        
        ans += min_v == MAX ? 0 : min_v;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 0; i < (1 << 25); i++) {
        if(__builtin_popcount(i) < 5) {
            masks.push_back(i); 
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
