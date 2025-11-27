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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::string ans(M, 'B');
    for(int i = 0; i < N; i++) {
        if(A[i] < M + 1 - A[i]) {
            if(ans[A[i] - 1] == 'B') {
                ans[A[i] - 1] = 'A';
            } else {
                ans[M - A[i]] = 'A';
            }
        } else {
            if(ans[M - A[i]] == 'B') {
                ans[M - A[i]] = 'A';
            } else {
                ans[A[i] - 1] = 'A';
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
