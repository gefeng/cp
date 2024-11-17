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

    std::vector<int> save_max(N, 0);
    std::vector<int> ans(N);
    for(int i = 0; i < N; i++) {
        save_max[i] = i == 0 ? A[i] : std::max(A[i], save_max[i - 1]);
        ans[i] = save_max[i];
    }

    int min_v = A[N - 1];
    int min_p = N - 1;
    for(int i = N - 2; i >= 0; i--) {
        int h = save_max[i];
        if(h > min_v) {
            ans[i] = std::max(ans[i], ans[min_p]); 
        }
        if(A[i] < min_v) {
            min_v = A[i];
            min_p = i;
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
