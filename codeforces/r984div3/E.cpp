#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, Q;
    std::cin >> N >> K >> Q;
    
    std::vector<std::vector<int>> A(N, std::vector<int>(K, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::vector<int>> a(K, std::vector<int>(N, 0));

    for(int i = 0; i < K; i++) {
        for(int j = 0; j < N; j++) {
            if(j == 0) {
                a[i][j] = A[j][i];
            } else {
                A[j][i] |= A[j - 1][i];
                a[i][j] = A[j][i];
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        int M;
        std::cin >> M;

        int l = 0;
        int r = N - 1;
        while(M--) {
            int R, C;
            char O;
            std::cin >> R >> O >> C;
            R -= 1;
            
            if(O == '>') {
                int j = std::upper_bound(a[R].begin(), a[R].end(), C) - a[R].begin();
                l = std::max(l, j);
            } else {
                int j = std::lower_bound(a[R].begin(), a[R].end(), C) - a[R].begin();
                r = std::min(r, j - 1);
            }
        }

        std::cout << (l <= r && l >= 0 ? l + 1 : -1) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
