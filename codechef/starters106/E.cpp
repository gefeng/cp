#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(int N, std::vector<std::vector<int>>& G, int v, int d, std::vector<int>& diff) {
    int size = 1; 
    for(int nei : G[v]) {
        size += dfs(N, G, nei, d + 1, diff);
    }

    diff[d] += 1;
    diff[N - size + 1] -= 1;
    return size;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> G(N);
    std::vector<int> indegree(N, 0);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        indegree[V] += 1;
    }

    int root = -1;
    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            root = i;
            break;
        } 
    }

    std::vector<int> diff(N + 1, 0);
    dfs(N, G, root, 0, diff); 

    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += diff[i];
        std::cout << sum << " \n"[i == N - 1];
    }
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
