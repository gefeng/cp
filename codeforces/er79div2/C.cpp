#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    std::vector<int> B(M);
    std::vector<int> pos(N + 1, -1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]] = i;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    int64_t ans = 0;
    int r = -1;
    for(int i = 0; i < M; i++) {
        int p = pos[B[i]]; 
        if(p <= r) {
            ans += 1;
        } else {
            ans += (p - i) * 2 + 1;
            r = p;
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
