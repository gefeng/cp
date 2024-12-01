#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = int(1e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
    }

    for(int i = 0; i < N - 1; i++) {
        G[i].push_back(i + 1);
    }

    std::queue<int> q;
    std::vector<int> best(N, INF);
    q.push(0);
    best[0] = 0;
    
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int v = q.front();
            q.pop();
            
            for(int nei : G[v]) {
                int nd = best[v] + 1;
                if(best[nei] > nd) {
                    best[nei] = nd;
                    q.push(nei);
                }
            }
        }
    }
    
    std::vector<int> win(N, 0);
    for(int i = 0; i < N - 1; i++) {
        int l = std::min(N - 1, i + 1);
        int r = std::min(N - 1, *std::max_element(G[i].begin(), G[i].end()) - best[i] - 2);
        if(l <= r) {
            win[l] += 1;
            win[r + 1] -= 1;
        }
    }

    std::string ans(N - 1, '1');
    int now = 0;
    for(int i = 0; i < N - 1; i++) {
        now += win[i];
        if(now > 0) {
            ans[i] = '0';
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
