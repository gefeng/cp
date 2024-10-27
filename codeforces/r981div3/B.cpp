#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }
    
    std::vector<std::vector<int>> vis(N, std::vector<int>(N, 0));
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!vis[i][j] && A[i][j] < 0) {
                int r = i;
                int c = j;
                int cnt = 0;
                while(r >= 0 && c >= 0 && r < N && c < N) {
                    if(A[r][c] < 0) {
                        cnt = std::max(-A[r][c], cnt);
                        vis[r][c] = 1;
                    }
                    r += 1;
                    c += 1;
                }

                ans += cnt;
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
