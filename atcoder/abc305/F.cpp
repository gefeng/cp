#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void query(int v) {
    std::cout << v + 1 << std::endl;
}

bool dfs(int N, std::vector<bool>& vis, int v, int p) {
    if(v != 0) {
        query(v);
    }

    vis[v] = true;

    int K;
    std::cin >> K;

    std::vector<int> neis;
    for(int i = 0; i < K; i++) {
        int U;
        std::cin >> U;

        U -= 1;

        neis.push_back(U);
    }

    for(int nei : neis) {
        if(!vis[nei]) {
            if(nei == N - 1) {
                query(nei);
                std::string S;
                std::cin >> S;
                return true;
            } else if(dfs(N, vis, nei, v)) {
                return true;
            }
        }
    }

    query(p);
    std::cin >> K;
    for(int i = 0; i < K; i++) {
        int X;
        std::cin >> X;
    }
    
    return false;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<bool> vis(N, false);
    vis[0] = true;
    
    dfs(N, vis, 0, -1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
