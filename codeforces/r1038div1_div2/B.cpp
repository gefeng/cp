#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::array<int64_t, 4>> A(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 4; j++) {
            std::cin >> A[i][j];
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        ans += std::max(int64_t(0), A[i][2] - A[i][0]);
        if(A[i][1] > A[i][3]) {
            ans += A[i][1] - A[i][3];
            if(A[i][2] < A[i][0]) {
                ans += A[i][2];
            } else {
                ans += A[i][0];
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
