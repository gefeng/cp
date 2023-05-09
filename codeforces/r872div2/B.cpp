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

    if(N < M) {
        std::swap(N, M);
    }

    std::vector<int> A(N * M);
    for(int i = 0; i < N * M; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int sum1 = 0;
    int d1 = A.back() - A[0]; 
    int d2 = A.back() - A[1];

    sum1 += d2 * (M - 1);
    sum1 += d1 * (N * M - M); 

    int sum2 = 0;
    d1 = A.back() - A[0];
    d2 = A[N * M - 2] - A[0];
    sum2 += d2 * (M - 1);
    sum2 += d1 * (N * M - M); 

    std::cout << std::max(sum1, sum2) << '\n';
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
