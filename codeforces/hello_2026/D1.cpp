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

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::queue<std::pair<int, int>> q;
    q.emplace(0, -1);

    int max_v = 1;
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            auto [v, p] = q.front();
            q.pop();
            
            for(int nei : G[v]) {
                if(nei != p) {
                    q.emplace(nei, v);
                }
            }
        }
        max_v = std::max(max_v, static_cast<int>(q.size()));
    }

    int ans = 1;
    q.emplace(0, -1);
    while(!q.empty()) {
        int size = q.size();
        std::vector<int> now;
        int max_c = 0;
        for(int i = 0; i < size; i++) {
            auto [v, p] = q.front();
            q.pop();
            now.push_back(v);
            
            int c = 0;
            for(int nei : G[v]) {
                if(nei != p) {
                    q.emplace(nei, v);
                    c += 1;
                }
            }
            max_c = std::max(max_c, c);
        }

        if(q.size() == max_v) {
            ans = std::max(ans, max_v + (max_c == max_v ? 1 : 0));
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
