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

    int64_t sum = 0;
    sum = std::accumulate(A.begin(), A.end(), int64_t(0));

    if(sum % N != 0) {
        std::cout << -1 << '\n';
        return;
    }

    int t = sum / N;
    std::vector<std::array<int, 3>> ans;
    for(int i = 1; i < N; i++) {
        int rem = A[i] % (i + 1);
        if(rem == 0) {
            ans.push_back({i + 1, 1, A[i] / (i + 1)});
        } else {
            int need = i + 1 - rem;
            ans.push_back({1, i + 1, need});
            ans.push_back({i + 1, 1, (A[i] + need) / (i + 1)});
        }
        A[i] = 0;
    }

    for(int i = 1; i < N; i++) {
        ans.push_back({1, i + 1, t});
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << ans[i][j] << " \n"[j == 2];
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
