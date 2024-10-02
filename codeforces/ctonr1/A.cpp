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

    int max_v = 0;
    int min_v = int(2e9);
    int max_p = -1;
    int min_p = -1;
    for(int i = 0; i < N; i++) {
        if(max_v < A[i]) {
            max_v = A[i];
            max_p = i;
        }
        if(min_v > A[i]) {
            min_v = A[i];
            min_p = i;
        }
    }

    std::cout << max_p + 1 << ' ' << min_p + 1 << '\n';
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
