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

    std::vector<int> ans(N * 3, -1);
    int now = 1;
    for(int i = 0; i < N * 3; i += 3) {
        ans[i] = now++;
    }

    for(int i = 0; i < N * 3; i++) {
        if(ans[i] == -1) {
            ans[i] = now++;
        }
        std::cout << ans[i] << " \n"[i == N * 3 - 1];
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
