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
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int r = N - 1;
    std::vector<std::pair<int, int>> ans(N);
    for(int i = N - 1; i >= 0; i--) {
        int j = std::lower_bound(B.begin(), B.end(), A[i]) - B.begin();

        ans[i] = {B[j] - A[i], B[r] - A[i]};

        if(j == i) {
            r = i - 1;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i].first << " \n"[i == N - 1];
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i].second << " \n"[i == N - 1];
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
