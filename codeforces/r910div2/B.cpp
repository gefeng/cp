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
 
    int64_t ans = 0;
    int64_t nxt = A.back();
    for(int i = N - 2; i >= 0; i--) {
        if(A[i] > nxt) {
            int k = (A[i] + nxt - 1) / nxt;
            nxt = A[i] / k;
            ans += k - 1;
        } else {
            nxt = A[i];
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
