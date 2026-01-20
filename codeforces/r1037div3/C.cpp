#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    K -= 1;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int h = A[K];
    
    std::ranges::sort(A);

    A.erase(std::unique(A.begin(), A.end()), A.end());
    int water = 1;
    int pre = -1;
    for(auto it = std::ranges::lower_bound(A, h); it != A.end(); it++) {
        if(pre != -1) {
            water += *it - pre;
        } 
        if(pre != -1 && water > pre + 1) {
            std::cout << "No" << '\n';
            return;
        }
        pre = *it;
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
