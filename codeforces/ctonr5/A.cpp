#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    for(int i = 0; i < N; i++) { 
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    LL sum1 = 0LL;
    LL sum2 = 0LL;
    for(int i = 0; i < N; i++) {
        sum1 += A[i];
    }

    for(int i = 0; i < M; i++) {
        sum2 += B[i];
    }

    if(sum1 == sum2) {
        std::cout << "Draw" << '\n';
    } else if(sum1 > sum2) {
        std::cout << "Tsondu" << '\n';
    } else {
        std::cout << "Tenzing" << '\n';
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
