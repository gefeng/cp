#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    A.back() -= 1;
    std::sort(A.begin(), A.end());
    
    if(A.back() - A[0] <= K) {
        int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
        std::cout << (sum % 2 == 0 ? "Tom" : "Jerry") << '\n';
        return;
    }

    std::cout << "Jerry" << '\n';
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
