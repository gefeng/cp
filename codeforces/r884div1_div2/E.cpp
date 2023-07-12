#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

bool dfs(std::vector<std::vector<std::pair<int, int>>>& G, int v, int c, std::vector<int>& color) {
    if(color[v] != -1) {
        return color[v] == c;
    } 

    color[v] = c;

    for(std::pair<int, int>& nei : G[v]) {
        if(!dfs(G, nei.first, c ^ nei.second, color)) {
            return false; 
        }
    }

    return true;
}

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<std::pair<int, int>>> G(M + N);
    for(int i = 0; i < K; i++) {
        int X1, X2, Y1, Y2;
        std::cin >> X1 >> Y1 >> X2 >> Y2;
        X1 -= 1;
        X2 -= 1;
        Y1 -= 1;
        Y2 -= 1;

        G[std::min(X1, X2)].emplace_back(std::min(Y1, Y2) + N, X1 + Y1 == X2 + Y2);
        G[std::min(Y1, Y2) + N].emplace_back(std::min(X1, X2), X1 + Y1 == X2 + Y2);
    }

    std::vector<int> color(N + M, -1);
    for(int i = 0; i < N + M; i++) {
        if(color[i] == -1) {
            if(!dfs(G, i, 0, color)) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    std::cout << "Yes" << '\n';
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
