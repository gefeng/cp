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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t a = M;
    int64_t b = M;
    int res = 2; // 0: lose  1: win 2: tie
    int64_t sum = 0;
    int64_t cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] < 0) {
            a += A[i];
        } else {
            b -= A[i];
            sum += A[i];
            cnt += 1;
        }
        if(a <= 0) {
            res = 0;  
            break;
        } 
        if(b <= 0) {
            res = 1; 
            break;
        }
    } 

    for(int i = 0; i < Q; i++) {
        int X;
        std::cin >> X;
        
        if(res == 1) {
            std::cout << "Yes" << '\n';
            continue;
        }
        
        if(res == 0) {
            std::cout << (X * cnt + sum >= M ? "Yes" : "No") << '\n';
        } else {
            std::cout << (X * cnt + sum >= M ? "Yes" : "Tie") << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
