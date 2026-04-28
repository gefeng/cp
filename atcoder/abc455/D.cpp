#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<std::pair<int, int>> A(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first--;
        A[i].second--;
    }

    std::vector<int> where(N, 0);
    std::iota(where.begin(), where.end(), 0);

    std::vector<int> up(N, -1);
    std::vector<int> down(N, -1);
    
    for(int i = 0; i < Q; i++) {
        auto [c, p] = A[i];
        if(down[c] != -1) {
            up[down[c]] = -1;
            down[c] = -1;
        } 
        up[p] = c;
        down[c] = p;
    }

    std::vector<int> vis(N, 0);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }

        int now = i;
        while(down[now] != -1) {
            now = down[now];
        }
        
        int x = where[now];
        while(now != -1) {
            vis[now] = 1;
            where[now] = x;
            now = up[now];
        }
    }

    std::vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        ans[where[i]]++;
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
