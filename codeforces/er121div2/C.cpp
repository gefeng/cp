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
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int64_t ans = 0;
    int64_t begin = A.back() - B.back() + 1;
    int64_t end = A.back();
    for(int i = N - 2; i >= 0; i--) {
        int64_t t = A[i] - B[i] + 1;
        if(begin > A[i]) {
            ans += (end - begin + 2) * (end - begin + 1) / 2;
            begin = t;
            end = A[i];
        } else {
            begin = std::min(begin, t);
        } 
    }
    
    ans += (end - begin + 2) * (end - begin + 1) / 2;

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
