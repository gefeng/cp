#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> ans(N, 0);
    ans[0] = 1;
    int size = 1;
    for(int i = 1, j = 2; i < N; i++) {
        int64_t d = A[i] - A[i - 1];
        if(size - d >= 0) {
            ans[i] = ans[size - d];
        } else {
            ans[i] = j++;
        }
        size += 1;
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
