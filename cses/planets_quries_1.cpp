#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

constexpr int LOG = 30;

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<std::vector<int>> up(LOG + 1, std::vector<int>(N, -1));
    
    for(int i = 0; i < N; i++) {
        up[0][i] = A[i];
    }
    
    for(int i = 1; i <= LOG; i++) {
        for(int j = 0; j < N; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        } 
    }

    for(int i = 0; i < Q; i++) {
        int X, K;
        std::cin >> X >> K;

        X -= 1;

        int p = X;
        /*for(int i = LOG; i >= 0; i--) {
            if(K & (1 << i)) {
                p = up[i][p];
            }
        }*/

        for(int i = 0; i <= LOG; i++) {
            if(K & (1 << i)) {
                p = up[i][p];
            }
        }
        std::cout << p + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    run_case();
}
