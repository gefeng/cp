#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

bool dfs(std::vector<std::vector<int>>& G, int K, int v, int p, std::vector<int>& save_size) {
    save_size[v] = 1;
    int cnt_c = 0;
    for(int nei : G[v]) {
        if(nei == p) {
            continue;
        }
        if(!dfs(G, K, nei, v, save_size)) {
            return false;
        }
        if(save_size[nei]) {
            cnt_c += 1;
            save_size[v] += save_size[nei];
        }
    }

    if(save_size[v] > K) {
        return false;
    }

    if(save_size[v] < K) {
        if(cnt_c >= 2) {
            return false;
        }
    } else if(save_size[v] == K) {
        if(cnt_c > 2) {
            return false;
        }
        save_size[v] = 0;
    }
    return true;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N * K);
    for(int i = 0; i < N * K - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::vector<int> save_size(N * K, 0); 

    std::cout << (dfs(G, K, 0, -1, save_size) ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
