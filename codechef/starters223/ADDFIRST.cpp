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

    for(int i = 0; i < N; i++) {
        if(A[i] > B[i]) {
            std::cout << "No" << '\n';
            return;
        }
    }

    int max_v = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] < B[i] && max_v >= A[i]) {
            std::cout << "No" << '\n';
            return;
        }

        max_v = std::max(max_v, A[i]);
    }

    std::cout << "Yes" << '\n';
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
