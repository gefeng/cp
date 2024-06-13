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

    int ans = 1;
    for(int b = 0; b < 20; b++) {
        int pre = -1;
        int max_d = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] & (1 << b)) {
                max_d = std::max(max_d, i - pre);
                pre = i;
            }
        }

        if(pre != -1) {
            max_d = std::max(max_d, N - pre);
            ans = std::max(ans, max_d); 
        }
    }

    std::cout << ans << '\n';
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
