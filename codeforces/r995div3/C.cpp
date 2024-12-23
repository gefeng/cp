#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;
    
    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(K);
    for(int i = 0; i < K; i++) {
        std::cin >> B[i];
    }

    if(K == N) {
        std::cout << std::string(M, '1') << '\n';
        return;
    }
    
    std::string ans(M, '0');
    if(K == N - 1) {
        std::vector<int> knows(N, 0);
        for(int x : B) {
            knows[x - 1] = 1;
        }
        for(int i = 0; i < M; i++) {
            if(!knows[A[i] - 1]) {
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
