#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans(N, 0);
    std::vector<int> seen(N + 1, 0);
    for(int i = 0; i < N; i++) {
        if(!seen[A[i]]) {
            ans[i] = A[i];
            seen[A[i]] = 1;
        }
    }

    for(int i = 0, j = 1; i < N; i++) {
        if(ans[i] == 0) {
            while(seen[j]) {
                j += 1;
            } 
            seen[j] = 1;
            ans[i] = j;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
