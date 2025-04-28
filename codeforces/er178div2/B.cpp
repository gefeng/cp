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

    std::vector<int> max_v(N, 0);
    for(int i = 0; i < N; i++) {
        max_v[i] = i == 0 ? A[i] : std::max(max_v[i - 1], A[i]);
    }

    int64_t sum = 0;
    std::vector<int64_t> ans;
    for(int i = N - 1; i >= 0; i--) {
        sum += A[i]; 
        int64_t res = sum;
        if(i) {
            int v = max_v[i - 1];
            if(v > A[i]) {
                res -= A[i];
                res += v;
            }
        }

        ans.push_back(res);
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
