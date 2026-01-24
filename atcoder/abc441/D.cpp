#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <map>

void run_case() {
    int N, M, L, S, T;
    std::cin >> N >> M >> L >> S >> T;
    
    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
    }

    std::queue<std::pair<int, int>> q;
    std::map<int, int> ans;
    q.emplace(0, 0);
    
    for(int _ = 0; _ < L; _++) {
        int size = q.size();
        while(size--) {
            auto [d, v] = q.front();
            q.pop();
        
            for(auto [nei, w] : G[v]) {
                if(d + w > T) {
                    continue;
                }
                q.emplace(d + w, nei);
            }
        }
    }

    while(!q.empty()) {
        auto [d, v] = q.front();
        q.pop();
        ans[v] = std::max(ans[v], d);
    }

    for(auto [v, d] : ans) {
        if(d >= S) {
            std::cout << v + 1 << ' ';
        }
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
