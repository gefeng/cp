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

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::vector<int>> dist(M + N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int x = i + j;
            int y = N - 1 - i + M - 1 - j;
            if(x <= y) {
                dist[x].push_back(A[i][j]);
            } else {
                dist[y].push_back(A[i][j]);
            }
        } 
    }

    int ans = 0;
    for(int i = 0; i <= N - 1 + M - 1; i++) {
        int size = dist[i].size();
        if((N + M - 2) % 2 == 0 && i == (N + M - 2) / 2) {
            continue;
        }
        int cnt = 0;
        for(int j = 0; j < size; j++) {
            cnt += dist[i][j];
        }
        ans += std::min(size - cnt, cnt);
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
