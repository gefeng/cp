#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

bool dfs(int H, int W, std::vector<std::pair<int, int>>& a, int r, int c, int used, std::vector<std::vector<int>>& cover) {
    if(r == H) {
        return used == (1 << a.size()) - 1;
    }

    if(c == W) {
        return dfs(H, W, a, r + 1, 0, used, cover);
    }

    if(cover[r][c]) {
        return dfs(H, W, a, r, c + 1, used, cover); 
    }

    int n = a.size();
    for(int i = 0; i < n; i++) {
        if(used & (1 << i)) {
            continue; 
        }

        auto [x, y] = a[i];
        for(int t = 0; t < 2; t++) {
            bool ok = true;
            if(r + y - 1 < H && c + x - 1 < W) {
                for(int j = 0; j < y; j++) {
                    for(int k = 0; k < x; k++) {
                        if(cover[r + j][c + k]) {
                            ok = false;
                            break;
                        }
                    }

                    if(!ok) {
                        break;
                    }
                }
            } else {
                ok = false;
            }

            if(ok) {
                for(int j = 0; j < y; j++) {
                    for(int k = 0; k < x; k++) {
                        cover[r + j][c + k] = 1;
                    }
                }

                if(dfs(H, W, a, r, c + 1, used | (1 << i), cover)) {
                    return true;
                }

                for(int j = 0; j < y; j++) {
                    for(int k = 0; k < x; k++) {
                        cover[r + j][c + k] = 0;
                    }
                }
            }

            if(x == y) {
                break;
            }
            std::swap(x, y);
        }
    }

    return false;
}

void run_case() {
    int N, H, W;
    std::cin >> N >> H >> W;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    for(int m = 1; m < (1 << N); m++) {
        std::vector<std::pair<int, int>> a;
        for(int i = 0; i < N; i++) {
            if(m & (1 << i)) {
                a.emplace_back(A[i].first, A[i].second);
            }
        }

        std::vector<std::vector<int>> cover(H, std::vector<int>(W, 0));
        if(dfs(H, W, a, 0, 0, 0, cover)) {
            std::cout << "Yes" << '\n';
            return;
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
