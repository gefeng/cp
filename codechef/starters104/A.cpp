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

    std::vector<int> save_max(N, 0);
    for(int i = N - 2; i >= 0; i--) {
        save_max[i] = std::max(save_max[i + 1], A[i + 1]);
    } 
    
    int max_v = A[0];
    for(int i = 1; i < N - 1; i++) {
        int v = std::min(max_v, save_max[i]);
        if(v > A[i]) {
            A[i] = v;
        }

        max_v = std::max(max_v, A[i]);
    }

    int64_t sum = 0;
    for(int x : A) {
        sum += x;
    }

    std::cout << sum << '\n';
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
