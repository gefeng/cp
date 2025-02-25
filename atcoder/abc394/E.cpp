#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> dist(N, std::vector<int>(N, INF));
    std::queue<std::pair<int, int>> q;
    
    for(int i = 0; i < N; i++) {
        dist[i][i] = 0;
        q.emplace(i, i);
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j] != '-' && i != j) {
                dist[i][j] = 1;
                q.emplace(i, j);
            } 
        }
    }

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(A[i][r] == A[c][j] && A[i][r] != '-' && dist[i][j] > dist[r][c] + 2) {
                    dist[i][j] = dist[r][c] + 2; 
                    q.emplace(i, j);
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << (dist[i][j] == INF ? -1 : dist[i][j]) << " \n"[j == N - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
