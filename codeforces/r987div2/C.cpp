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
    // 12341234
    // len = 8
    int N;
    std::cin >> N;
    
    std::vector<int> ans(N, 0);
    if(N % 2 == 0) {
        //11223344    
        for(int i = 0, j = 1; i < N; i += 2, j++) {
            ans[i] = j; 
            ans[i + 1] = j;
        }
    } else {
        if(N < 27) {
            std::cout << -1 << '\n';
            return;
        }

        ans[0] = 1;
        ans[9] = 1;
        ans[25] = 1;
        ans[22] = 2;
        ans[26] = 2;
        for(int i = 0, j = 3; i < N; i++) {
            if(ans[i] != 0) {
                continue;
            }
            ans[i] = j;
            ans[i + 1] = j;
            j += 1;
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
