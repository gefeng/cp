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

    std::vector<int> A(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans(N);
    ans[0] = A[0] + 1;
    for(int i = 1; i < N; i++) {
        if(i == N - 1) {
            ans[i] = ans[i - 1] + A[i - 1];
        } else {
            int c = (A[i] - A[i - 1] + ans[i - 1]) / ans[i - 1];
            ans[i] = c * ans[i - 1] + A[i - 1]; 
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
