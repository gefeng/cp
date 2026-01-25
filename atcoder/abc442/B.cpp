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

    int v = 0;
    int f = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == 1) {
            v += 1;
        } else if(A[i] == 2) {
            v = std::max(0, v - 1);
        } else {
            f ^= 1;
        }
        
        std::cout << (f && v > 2 ? "Yes" : "No") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
