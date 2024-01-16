#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;
    K += 1;
    
    std::vector<std::string> G(N);
    std::vector<std::string> g(N);
    for(int i = 0; i < N; i++) {
        std::cin >> G[i];
        g[i] = G[i];
    }

    auto solve = [&]() {
        std::vector<std::vector<int>> psum1(N + 1, std::vector<int>(M + 1, 0));
        std::vector<std::vector<int>> psum2(N + 1, std::vector<int>(M + 2, 0));

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                psum1[i + 1][j + 1] = psum1[i][j + 1] + (g[i][j] == '#' ? 1 : 0);
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                psum2[i + 1][j + 1] = psum2[i][j + 2] + (g[i][j] == '#' ? 1 : 0);
            }
        }

        int ans = 0;
        std::vector<std::vector<int>> save(N + 1, std::vector<int>(M + 1, 0));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                int sum = save[i + 1][j]; 
                sum += psum1[i + 1][j + 1] - psum1[std::max(0, i - K + 1)][j + 1];
                
                int r1 = i;
                int c1 = j - K;
                if(c1 < 0) {
                    r1 += c1;
                    c1 = 0;
                }

                int r2 = i - K + 1;
                int c2 = j - 1;
                if(r2 < 0) {
                    c2 += r2;
                    r2 = 0;
                }

                if(r1 >= 0 && c1 >= 0 && r2 >= 0 && c2 >= 0) {
                    sum -= psum2[r1 + 1][c1 + 1] - psum2[r2][c2 + 2];
                }
                save[i + 1][j + 1] = sum;

                ans = std::max(ans, sum);
            }
        }

        return ans;
    };

    int ans = solve();
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            g[i][j] = G[i][M - 1 - j];
        }
    }
    ans = std::max(ans, solve());

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            g[i][j] = G[N - 1 - i][j];
        }
    }
    ans = std::max(ans, solve());
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            g[i][j] = G[N - 1 - i][M - 1 - j];
        }
    }
    ans = std::max(ans, solve());

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
