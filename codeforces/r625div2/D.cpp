#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = int(2e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N);
    std::vector<std::vector<int>> R(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        R[V].push_back(U);
    }

    int K;
    std::cin >> K;
    std::vector<int> A(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::queue<int> q;
    std::vector<int> dist(N, INF);
    q.push(A.back());
    dist[A.back()] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        for(int nei : R[v]) {
            if(dist[nei] == INF) {
                dist[nei] = dist[v] + 1;
                q.push(nei);
            }
        }
    }

    int min_v = 0;
    int max_v = 0;
    for(int i = 1; i < K - 1; i++) {
        int p = A[i - 1];
        int v = A[i];
        int min_d = INF;
        int cnt = 0;
        for(int nei : G[p]) {
            if(dist[nei] < min_d) {
                min_d = dist[nei];
                cnt = 1;
            } else if(dist[nei] == min_d) {
                cnt += 1;
            }
        }

        if(dist[v] != min_d) {
            max_v += 1;
            min_v += 1;
        } else {
            if(cnt > 1) {
                max_v += 1;
            }
        }
    }

    std::cout << min_v << ' ' << max_v << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
