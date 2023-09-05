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

    std::vector<std::vector<int>> pos(N + 1);
    for(int i = 0; i < N; i++) {
        pos[A[i]].push_back(i);
    }

    int64_t ans = 0;
    for(int i = 1; i <= N; i++) {
        int sz = pos[i].size();
        if(sz < 2) {
            continue; 
        }

        int64_t cnt = 0;
        int64_t sum = 0;
        for(int j = 1; j < sz; j++) {
            sum += pos[i][j] - pos[i][j - 1] - 1;
            cnt += sum;
        }

        for(int j = 1; j < sz; j++) {
            ans += cnt;
            cnt -= (int64_t)(sz - j) * (pos[i][j] - pos[i][j - 1] - 1);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
