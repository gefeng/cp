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

    int max_v = *std::max_element(A.begin(), A.end());

    bool unique = true;
    for(int i = 0; i < N; i++) {
        if(A[i] != max_v) {
            unique = false;
            break;
        }
    }

    if(unique) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << (A[i] == max_v ? 1 : 2) << " \n"[i == N - 1];
    }
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
