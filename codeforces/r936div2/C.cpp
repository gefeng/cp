#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(std::vector<std::vector<int>>& G, int v, int p, int x, int& cnt) {
    int size = 1;
    for(int nei : G[v]) {
        if(nei != p) {
            size += dfs(G, nei, v, x, cnt);
        }
    } 

    if(p == -1) {
        if(size < x) {
            cnt -= 1;
        }
    } else {
        if(size >= x) {
            cnt += 1;
            size = 0;
        }
    }

    return size;
}

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }

    int lo = 1;
    int hi = N;
    int ans = 1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        int cnt = 0;
        dfs(G, 0, -1, mid, cnt);
        
        if(cnt >= K) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1; 
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
