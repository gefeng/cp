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
    int N;
    std::cin >> N;
    
    std::vector<int> A(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }

    int sum = std::accumulate(A.begin(), A.end(), 0);
    
    std::cout << 0 - sum << '\n';
    
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
