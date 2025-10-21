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
    int N, X;
    std::cin >> N >> X;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << (A[0] == X ? "Yes" : "No") << '\n';
        return;
    }

    int sum = std::accumulate(A.begin(), A.end(), 0);
    std::cout << (sum % N == 0 && sum / N == X ? "Yes" : "No") << '\n';
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
