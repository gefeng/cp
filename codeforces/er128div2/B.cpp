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

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == 'R') {
                bool ok = true;
                for(int r = 0; r < N; r++) {
                    for(int c = 0; c < M; c++) {
                        if(A[r][c] == 'R' && (r < i || c < j)) {
                            ok = false;
                        }
                    }
                }
                if(ok) {
                    std::cout << "YES" << '\n';
                    return;
                }
            }
        }
    }

    std::cout << "NO" << '\n';
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
