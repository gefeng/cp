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
    std::vector<std::vector<int>> pos(N + 1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]].push_back(i);
    }

    std::vector<int> ans(N + 1, 0);
    for(int c = 1; c <= N; c++) {
        int size = pos[c].size();
        if(size == 0) {
            continue;
        }
        int len = 1;
        int p = pos[c][0];
        for(int i = 1; i < size; i++) {
            if((pos[c][i] - p) % 2 == 1) {
                len += 1;
                p = pos[c][i];
            }
        }
        ans[c] = std::max(ans[c], len);
    }

    for(int i = 1; i <= N; i++) {
        std::cout << ans[i] << " \n"[i == N];
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
