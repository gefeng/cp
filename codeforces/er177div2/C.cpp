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

    std::vector<int> A(N);
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int> solved(N, 0);

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int p = B[i] - 1;

        while(!solved[p]) {
            cnt += 1;
            solved[p] = 1;
            p = A[p] - 1;
        }
        
        std::cout << cnt << " \n"[i == N - 1];  
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
