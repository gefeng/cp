#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::pair<int, int>> B(M);
    std::vector<std::vector<int>> m(N);
    std::vector<int> like(N, 0);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i].first >> B[i].second;
        B[i].first -= 1;
        B[i].second -= 1;
        like[B[i].first] += 1;
        like[B[i].second] += 1;
        m[B[i].first].push_back(i);
        m[B[i].second].push_back(i);
    }
    
    std::vector<int> ans;
    std::vector<int> now;
    std::vector<int> vis(M, 0);
    for(int i = 0; i < N; i++) {
        if(like[i] <= A[i]) {
            now.push_back(i);
        }
    }

    while(!now.empty()) {
        std::vector<int> nxt;
        
        for(int i : now) {
            for(int j : m[i]) {
                if(vis[j]) {
                    continue;
                }
                vis[j] = 1;
                ans.push_back(j);
                auto [x, y] = B[j];
                if(x != i) {
                    if(--like[x] == A[x]) {
                        nxt.push_back(x);
                    }
                }
                if(y != i) {
                    if(--like[y] == A[y]) {
                        nxt.push_back(y);
                    }
                }
            } 
        }

        now = std::move(nxt);
    }

    if(ans.size() != M) {
        std::cout << "DEAD" << '\n';
        return;
    }
    
    std::ranges::reverse(ans);

    std::cout << "ALIVE" << '\n';
    for(int i = 0; i < M; i++) {
        std::cout << ans[i] + 1 << " \n"[i == M - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
