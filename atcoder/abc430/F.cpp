#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<std::vector<int>> G(N);
    std::vector<std::vector<int>> R(N);
    std::vector<int> degree1(N, 0);
    std::vector<int> degree2(N, 0);
    for(int i = 0; i < N - 1; i++) {
        if(S[i] == 'L') {
            G[i + 1].push_back(i); 
            R[i].push_back(i + 1);
            degree1[i] += 1;
            degree2[i + 1] += 1;
        } else {
            G[i].push_back(i + 1);
            R[i + 1].push_back(i);
            degree1[i + 1] += 1;
            degree2[i] += 1;
        }
    }

    auto topo = [](std::vector<std::vector<int>>& G, std::vector<int>& degree, std::vector<int>& dp) {
        int n = G.size();
        std::queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int now = q.front();
            q.pop();
            
            for(int nei : G[now]) {
                dp[nei] += dp[now] + 1;
                if(--degree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
    };

    std::vector<int> dp1(N, 0);
    std::vector<int> dp2(N, 0);

    topo(G, degree1, dp1);
    topo(R, degree2, dp2);

    std::vector<int> diff(N + 1, 0);
    for(int i = 0; i < N; i++) {
        diff[dp1[i]] += 1;
        diff[N - dp2[i]] -= 1;
    }

    int rolling  = 0;
    for(int i = 0; i < N; i++) {
        rolling += diff[i];
        std::cout << rolling << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
