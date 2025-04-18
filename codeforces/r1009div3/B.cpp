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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    if(N == 1) {
        std::cout << A[0] << '\n';
        return;
    }

    int64_t now = A.back() + A[N - 2] - 1;
    for(int i = N - 3; i >= 0; i--) {
        now = A[i] + now - 1; 
    }

    std::cout << now << '\n';
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
