#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> vis(N * 2, 0);
    std::vector<std::pair<int, int>> E;
    for(int i = 0; i < K; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        if(U > V) {
            std::swap(U, V);
        }
        E.emplace_back(U, V);
        vis[V] = 1;
        vis[U] = 1;
    }

    std::vector<int> rem;
    for(int i = 0; i < N * 2; i++) {
        if(vis[i]) {
            continue;
        }
        rem.push_back(i); 
    }

    int size = rem.size();
    for(int i = 0; i < size / 2; i++) {
        E.emplace_back(rem[i], rem[i + size / 2]);
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        auto [u, v] = E[i];
        for(int j = 0; j < i; j++) {
            auto [x, y] = E[j];
            
            if(x > u && x < v && y > u && y < v) {
                continue;
            }

            if((x < u || x > v) && (y < u || y > v)) {
                continue;
            }

            ans += 1;
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
