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
    
    std::vector<int> ans(N * 4, 0);
    
    int p = 0;
    for(int i = 0; i < N; i++, p += 2) {
        ans[p] = i + 1;
        ans[p + 1] = i + 1;
    }

    for(int i = 0; i < N; i++, p++) {
        ans[p] = i + 1;
    }

    for(int i = 0; i < N; i++, p++) {
        ans[p] = i + 1;
    }
    
    if(N > 2) {
        std::swap(ans[N * 4 - N - 1], ans[N * 4 - N - 2]);
        for(int i = 0; i < N * 4; i++) {
            std::cout << ans[i] << " \n"[i == N * 4 - 1];
        }
    } else {
        std::cout << "1 2 1 1 2 2 1 2" << '\n';
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
