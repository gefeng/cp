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

    int cnt_odd = 0;
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        if(A[i] % 2 == 1) {
            cnt_odd += 1;
        }

        int64_t res = 0;
        if(i == 0) {
            res = sum;
        } else {
            res = sum - (cnt_odd / 3);
            res -= cnt_odd % 3 == 1 ? 1 : 0;
        }

        std::cout << res << " \n"[i == N - 1];
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
