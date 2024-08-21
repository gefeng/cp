#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    } 
    
    int n = N * N;
    std::vector<int> a(n, 0);
    std::vector<int> removed(n, 0);
    std::vector<std::vector<int>> g(n);
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int h1 = i * N + j;
            for(int d = 0; d < 4; d++) {
                int ni = i + DR[d];
                int nj = j + DC[d];
                if(ni >= 0 && ni < N && nj >= 0 && nj < N) {
                    int h2 = ni * N + nj;
                    g[h2].push_back(h1);
                    a[h2] ^= 1;
                }
            } 
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            while(!g[i].empty() && removed[g[i].back()]) {
                g[i].pop_back();
            }
            
            if(!g[i].empty()) {
                int h1 = g[i].back();
                int r = h1 / N;
                int c = h1 % N;
                for(int d = 0; d < 4; d++) {
                    int nr = r + DR[d];
                    int nc = c + DC[d];
                    if(nr >= 0 && nr < N && nc >= 0 && nc < N) {
                        int h2 = nr * N + nc; 
                        a[h2] ^= 1;
                    }
                }
                removed[g[i].back()] = 1;
                g[i].pop_back();
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(!removed[i]) {
            ans ^= A[i / N][i % N];
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
