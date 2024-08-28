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

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};
constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::map<std::pair<int, int>, std::vector<int>> m;
    for(int i = 0; i < N; i++) {
        m[A[i]].push_back(i);
    }

    std::vector<std::array<int, 3>> dp(N, {INF, INF, INF});
    
    std::queue<int> q;
    for(int i = 0; i < N; i++) {
        for(int d = 0; d < 4; d++) {
            int nx = A[i].first + DR[d];
            int ny = A[i].second + DC[d];
            if(m.find({nx, ny}) == m.end()) {
                dp[i] = {1, nx, ny}; 
                q.push(i);
            }
        }
    } 

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int i = q.front();
            q.pop();
            
            auto [x, y] = A[i];

            for(int d = 0; d < 4; d++) {
                int nx = x + DR[d];
                int ny = y + DC[d];

                if(m.find({nx, ny}) != m.end()) {
                    std::vector<int>& a = m[{nx, ny}];
                    
                    for(int j : a) {
                        if(dp[j][0] == INF) {
                            dp[j] = {dp[i][0] + 1, dp[i][1], dp[i][2]};
                            q.push(j);
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << dp[i][1] << ' ' << dp[i][2] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
