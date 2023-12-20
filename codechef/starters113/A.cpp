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

    bool same = true;
    for(int i = 0; i < N; i++) {
        if(A[i] != A.front()) {
            same = false;
        }
    }

    if(same) {
        std::cout << "No" << '\n';
        return;
    }

    if(N == 4) {
        std::cout << (A[0] + A[1] != A[2] + A[3] ? "Yes" : "No") << '\n';
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
