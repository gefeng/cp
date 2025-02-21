#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

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

    int ans = 0;
    std::multiset<int> ms;
    for(int i = 0; i < N; i++) {
        int sum = G[i].size() == 1 ? 0 : G[i].size();
        int max_cnt = 0;
        for(int j : G[i]) {
            max_cnt = std::max(max_cnt, int(G[j].size()) - 1); 
        }

        ms.insert(G[i].size());
        ans = std::max(ans, sum + max_cnt - 1);
    }

    for(int i = 0; i < N; i++) {
        int sum = G[i].size() == 1 ? 0 : G[i].size();
        ms.erase(ms.find(G[i].size()));
        for(int j : G[i]) {
            ms.erase(ms.find(G[j].size()));
        }

        int max_cnt = ms.empty() ? 0 : *ms.rbegin();
        ans = std::max(ans, sum + max_cnt - 1);
        
        ms.insert(G[i].size());
        for(int j : G[i]) {
            ms.insert(G[j].size());
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
