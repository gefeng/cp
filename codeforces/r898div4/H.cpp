#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <queue>

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;

    A -= 1;
    B -= 1;
    
    std::vector<std::vector<int>> G(N);
    std::vector<int> indegree(N, 0);
    for(int i = 0; i < N; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
        indegree[U] += 1;
        indegree[V] += 1;
    }

    if(A == B) {
        std::cout << "NO" << '\n';
        return;
    }

    std::vector<int> cycle(N, 1);
    std::queue<int> q;

    for(int i = 0; i < N; i++) {
        if(indegree[i] == 1) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        cycle[v] = 0;

        for(int nei : G[v]) {
            if(--indegree[nei] == 1) {
                q.push(nei);
            }
        }
    }

    if(cycle[B]) {
        std::cout << "YES" << '\n';
        return;
    }

    q = std::queue<int>();
    std::vector<int> vis(N, 0);
    std::vector<int> dist1(N, 0);
    std::vector<int> dist2(N, 0);
    int d = 0;
    q.push(B);
    vis[B] = 1;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int v = q.front();
            q.pop();
            
            dist1[v] = d;

            for(int nei : G[v]) {
                if(!vis[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }
        d += 1;
    }

    q = std::queue<int>();
    vis = std::vector<int>(N, 0);
    q.push(A);
    vis[A] = 1;
    d = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            int v = q.front();
            q.pop();
            
            dist2[v] = d;

            for(int nei : G[v]) {
                if(!vis[nei]) {
                    vis[nei] = 1;
                    q.push(nei);
                }
            }
        }
        d += 1;
    }

    for(int v = 0; v < N; v++) {
        if(cycle[v] && dist1[v] < dist2[v]) {
            std::cout << "YES" << '\n';
            return;
        }
    }

    std::cout << "NO" << '\n';
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
