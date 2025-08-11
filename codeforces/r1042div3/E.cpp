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

    std::vector<int> a(A);
    for(int i = N - 1; i >= 0; i--) {
        if(a[i] == B[i]) {
            continue;
        }

        if(i == N - 1) {
            std::cout << "No" << '\n';
            return;
        }
        
        if(B[i] == (a[i] ^ A[i + 1])) {
            a[i] = a[i] ^ A[i + 1];
            continue;
        }
        
        if(B[i] == (a[i] ^ a[i + 1])) {
            a[i] = a[i] ^ a[i + 1];
            continue;
        }

        std::cout << "No" << '\n';
        return;
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
