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

    if(N % 2 == 1) {
        std::cout << "Mike" << '\n';
        return;
    }

    int min_v = *std::min_element(A.begin(), A.end());

    for(int i = 0; i < N; i++) {
        if(A[i] == min_v) {
            std::cout << (i % 2 == 0 ? "Joe" : "Mike") << '\n';
            return;
        }
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
