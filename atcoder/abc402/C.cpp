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
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> A(N + 1);
    std::vector<std::set<int>> B(M);
    
    for(int i = 0; i < M; i++) {
        int K;
        std::cin >> K;

        for(int j = 0; j < K; j++) {
            int X;
            std::cin >> X;

            A[X].push_back(i);
            B[i].insert(X);
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        
        for(int dish : A[X]) {
            B[dish].erase(X);
            if(B[dish].empty()) {
                ans += 1;
            }
        }

        std::cout << ans << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
