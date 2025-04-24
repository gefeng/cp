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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += B[i] != -1 ? 1 : 0;
    }
    
    if(cnt) {
        int sum = -1;
        for(int i = 0; i < N; i++) {
            if(B[i] != -1) {
                if(sum == -1) {
                    sum = A[i] + B[i];
                } else {
                    if(sum != A[i] + B[i]) {
                        std::cout << 0 << '\n';
                        return;
                    }
                }
            } 
        }
        
        for(int i = 0; i < N; i++) {
            if(B[i] == -1 && (sum - A[i] < 0 || sum - A[i] > K)) {
                std::cout << 0 << '\n';
                return;
            }
        }

        std::cout << 1 << '\n';
    } else {
        int l = std::min(K, *std::max_element(A.begin(), A.end()));
        int r = K + *std::min_element(A.begin(), A.end());
        std::cout << std::max(0, r - l + 1) << '\n';
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
