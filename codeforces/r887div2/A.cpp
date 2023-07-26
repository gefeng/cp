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
    
    int ans = (int)1e9;
    for(int i = 0; i < N - 1; i++) {
        if(A[i + 1] < A[i]) {
            ans = 0;
            break;
        } 

        int d = A[i + 1] - A[i];
        ans = std::min(ans, (d + 2) / 2);
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
