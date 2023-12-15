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

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end());

    int64_t sum = 0;
    std::vector<int> ans(N, 0);
    for(int i = 0; i < N; i++) {
        int j = i;
        sum += A[i].first;
        while(i + 1 < N && sum >= A[i + 1].first) {
            sum += A[i + 1].first;
            i += 1;
        }

        for(int k = j; k <= i; k++) {
            ans[A[k].second] = i;
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
