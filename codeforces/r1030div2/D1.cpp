#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int64_t P;
        std::cin >> P;

        int64_t p = P;
        int64_t d = 1;
        int64_t t = 0;

        if((p > A.back() && d == 1) || (p < A.front() && d == -1)) {
            std::cout << "Yes" << '\n';
            continue;
        } 

        int j = std::lower_bound(A.begin(), A.end(), p) - A.begin();
        t = A[j] - p; 
        
        bool leave = false;
        std::vector<std::vector<std::vector<int>>> vis(2, std::vector<std::vector<int>>(K, std::vector<int>(N, 0)));
        while(true) {
            if(t - B[j] >= 0 && (t - B[j]) % K == 0) {
                d = d == 1 ? -1 : 1;
            }

            if(vis[d == -1 ? 0 : 1][t % K][j]) {
                break;
            }
                
            vis[d == -1 ? 0 : 1][t % K][j] = 1;

            if(d == 1) {
                if(j == N - 1) {
                    leave = true;
                    break;
                }
            } else {
                if(j == 0) {
                    leave = true;
                    break;
                }
            }
            t += std::abs(A[j + d] - A[j]);
            j += d;
        }

        std::cout << (leave ? "Yes" : "No") << '\n';
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
