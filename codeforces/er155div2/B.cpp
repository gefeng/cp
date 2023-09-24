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

    std::vector<std::pair<int, int>> A(N);
    std::vector<std::pair<int, int>> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i].first;
        B[i].second = i;
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
        
    int64_t cost1 = 0;
    int64_t cost2 = 0;
    for(int i = 0; i < N; i++) {
        cost1 += A[0].first + B[i].first;
        cost2 += B[0].first + A[i].first;
    }     

    std::cout << std::min(cost1, cost2) << '\n'; 
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
