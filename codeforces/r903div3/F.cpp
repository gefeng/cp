#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void bfs(std::vector<std::vector<int>>& G, int s, std::vector<int>& dist) {
    std::queue<int> q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int v = q.front();
            q.pop();
            for(int nei : G[v]) {
                if(dist[nei] == -1) {
                    dist[nei] = dist[v] + 1;
                    q.emplace(nei);
                }
            }
        }
    }
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N, 0);
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < K; i++) {
        int V;
        std::cin >> V;
        V -= 1;
        A[V] = 1;
    }

    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    } 

    std::vector<int> dist1(N, -1);
    std::vector<int> dist2(N, -1);
    int a = -1;
    for(int i = 0; i < N; i++) {
        if(A[i]) {
            bfs(G, i, dist1);
            break;
        }
    }

    int max_d = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] && dist1[i] > max_d) {
            max_d = dist1[i];
            a = i;
        }
    }

    bfs(G, a, dist2);
    max_d = -1;
    for(int i = 0; i < N; i++) {
        if(A[i]) {
            max_d = std::max(max_d, dist2[i]);
        }
    }

    if(max_d == 0) {
        std::cout << 0 << '\n';
    } else {
        std::cout << (max_d + 1) / 2 << '\n';
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
