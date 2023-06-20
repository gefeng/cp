#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, std::vector<int>& res) {
    res.push_back(A[v]);
    for(int nei : G[v]) {
        dfs(G, A, nei, res);
    }
}

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        
        G[P].emplace_back(i + 1);
    }

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int v = 0; v < N; v++) {
        std::vector<int> res;
        dfs(G, A, v, res);

        int sz = res.size();
        int cnt = 0;
        for(int i = 0; i < sz; i++) {
            if(res[i] == -1) {
                cnt += 1;
            }
        }

        if(cnt < 2) {
            int cnt_missing = 0;
        
            std::vector<bool> seen(K + 1, false);
            for(int i = 0; i < sz; i++) {
                if(res[i] >= 0 && res[i] <= K) {
                    seen[res[i]] = true;
                }
            }

            for(int i = 0; i < K; i++) {
                if(!seen[i]) {
                    cnt_missing += 1;
                } 
            }

            if(cnt == 0) {
                if(!seen[K] && cnt_missing == 0) {
                    std::cout << "Alice" << '\n';
                    return;
                }
            } else {
                if(!seen[K] && cnt_missing < 2) {
                    std::cout << "Alice" << '\n';
                    return;
                }
            }
        }
    }

    std::cout << "Bob" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
