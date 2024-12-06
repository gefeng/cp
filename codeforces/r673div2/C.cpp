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

    std::vector<int> ka(N + 1, N + 1);
    for(int i = 1; i <= N; i++) {
        if(pos[i].empty()) {
            continue;
        }

        int pre = -1;
        int gap = 0;
        for(int p : pos[i]) {
            gap = std::max(gap, p - pre); 
            pre = p;
        }
        gap = std::max(gap, N - pre);

        ka[gap] = std::min(ka[gap], i);
    }


    for(int k = 1; k <= N; k++) {
        ka[k] = std::min(ka[k], ka[k - 1]);
        std::cout << (ka[k] == N + 1 ? -1 : ka[k]) << " \n"[k == N];
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
