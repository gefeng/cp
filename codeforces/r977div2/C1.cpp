#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, Q;
    std::cin >> N >> M >> Q;
    
    std::vector<int> A(N);
    std::vector<int> B(M);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    bool ok = true;
    std::vector<int> free(N + 1, 0);
    for(int i = 0, j = 0; i < M; ) {
        int k = i;
        while(i < M && B[i] == B[k]) {
            i += 1; 
        }
        
        if(B[k] == A[j]) {
            free[B[k]] = 1;
            if(++j == N) {
                break;
            }
        } else {
            if(!free[B[k]]) {
                ok = false;
                break;
            }
        }
    }

    std::cout << (ok ? "YA" : "TIDAK") << '\n';
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
