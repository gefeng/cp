#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> ans(N, 0);

    ans[N / 2] = 1;
    if(N > 1) {
        ans[0] = 2;    
    }
    if(N > 2) {
        ans[N - 1] = 3;
    }

    for(int i = 0, j = 4; i < N; i++) {
        if(ans[i] == 0) {
            ans[i] = j++;
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
