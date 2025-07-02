#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, P, K;
    std::cin >> N >> P >> K;

    P -= 1;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(K > 1) {
        std::cout << "Yes" << '\n';
        return;
    }

    int s = A[P];
    std::sort(A.begin(), A.end());
    
    std::cout << (s == A.back() ? "Yes" : "No") << '\n';
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
