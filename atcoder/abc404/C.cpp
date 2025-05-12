#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    std::vector<int> indegree(N, 0);
    std::vector<int> outdegree(N, 0);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
        indegree[V] += 1;
        indegree[U] += 1;
        outdegree[U] += 1;
        outdegree[V] += 1;
    }

    for(int i = 0; i < N; i++) {
        if(indegree[i] != 2 || outdegree[i] != 2) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::vector<int> vis(N, 0);
    int now = 0;
    while(!vis[now]) {
        vis[now] = 1;
        for(int nei : G[now]) {
            if(!vis[nei]) {
                now = nei;
                break;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(!vis[i]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
