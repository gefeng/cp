#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int M;
    std::cin >> M;

    std::set<int> all;
    std::vector<std::vector<int>> A(M);
    for(int i = 0; i < M; i++) {
        int N;
        std::cin >> N;
        for(int j = 0; j < N; j++) {
            int X;
            std::cin >> X;
            A[i].push_back(X);
            all.insert(X);
        }
    }

    std::set<int> s;

    std::vector<int> ans(M, 0);
    for(int i = M - 1; i >= 0; i--) {
        int winner = -1;
        for(int x : A[i]) {
            if(s.find(x) == s.end()) {
                winner = x; 
                break;
            }
        }

        if(winner == -1) {
            std::cout << -1 << '\n';
            return;
        }

        ans[i] = winner;

        for(int x : A[i]) {
            s.insert(x);
        }
    }

    for(int i = 0; i < M; i++) {
        std::cout << ans[i] << " \n"[i == M - 1];
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
