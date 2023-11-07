#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

bool dfs(std::vector<std::vector<int>>& G, std::vector<int>& color, int v, int c) {
    color[v] = c;
    
    for(int nei : G[v]) {
        if(color[nei] != -1 && color[nei] == c) {
            return false;
        }
        if(color[nei] == -1) {
            if(!dfs(G, color, nei, c ^ 1)) {
                return false;
            }
        }
    }
    
    return true;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    std::vector<int> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
        B[i] -= 1;
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    std::vector<int> color(N, -1);
    for(int i = 0; i < N; i++) {
        if(color[i] == -1) {
            if(!dfs(G, color, i, 0)) {
                std::cout << "No" << '\n';
                return;
            }
        }
    } 

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
