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

    bool inc = true;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            inc = false;
        }
    }

    if(inc) {
        std::cout << 0 << '\n';
        return;
    }

    if(A[0] == 1 || A.back() == N) {
        std::cout << 1 << '\n';
        return;
    }
    
    if(A[0] == N && A.back() == 1) {
        std::cout << 3 << '\n';
        return;
    }

    std::cout << 2 << '\n';
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
