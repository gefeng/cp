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

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += A[i];
        cnt += B[i];
    }

    if(cnt % 2 == 0) {
        std::cout << "Tie" << '\n';
        return;
    }

    int last = -1;
    for(int i = N - 1; i >= 0; i--) {
        if(A[i] != B[i]) {
            last = i;
            break;
        } 
    }

    std::cout << (last % 2 == 0 ? "Ajisai" : "Mai") << '\n';
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
