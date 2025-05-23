#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <numeric>

constexpr int INF = int(2e9);

void run_case() {
    int N, M, L;
    std::cin >> N >> M >> L;
    
    std::vector<int> A(L);
    for(int i = 0; i < L; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    std::sort(A.begin(), A.end());
    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
    int min_odd = INF;
    for(int x : A) {
        if(x % 2 == 1) {
            min_odd = std::min(min_odd, x);
        }
    }

    std::vector<std::vector<int>> dist(2, std::vector<int>(N, INF));
    std::queue<int> q;
    
    q.push(0);
    dist[0][0] = 0;

    int d = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            int v = q.front();
            q.pop();
            
            for(int nei : G[v]) {
                int p = (d + 1) % 2;
                if(dist[p][nei] > d + 1) {
                    dist[p][nei] = d + 1;
                    q.push(nei);
                }
            }
        }
        d += 1;
    }

    std::string ans(N, '0');
    for(int i = 0; i < N; i++) {
        if(dist[0][i] != INF && sum >= dist[0][i]) {
            if(sum % 2 == 0 || (min_odd != INF && sum - min_odd >= dist[0][i])) {
                ans[i] = '1';
            }
        }
        
        if(dist[1][i] != INF && sum >= dist[1][i]) {
            if(sum % 2 == 1 || (min_odd != INF && sum - min_odd >= dist[1][i])) {
                ans[i] = '1';
            }
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
