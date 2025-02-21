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

    for(int i = 0; i < N; i++) {
        if(A[i] < 0) {
            std::cout << "NO" << '\n';
            return;
        }
    } 
    
    std::cout << "YES" << '\n';
    int max_v = *std::max_element(A.begin(), A.end());
    std::cout << max_v + 1 << '\n';
    for(int i = 0; i <= max_v; i++) {
        std::cout << i << " \n"[i == max_v];
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
