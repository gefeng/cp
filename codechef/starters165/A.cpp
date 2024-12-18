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

    int max_v = 0;
    int max_p = -1;
    int ans = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(A[i] < max_v) {
            ans = std::max(ans, max_p - i);
        }

        if(A[i] > max_v) {
            max_v = A[i];
            max_p = i;
        } else if(A[i] == max_v) {
            max_p = i;
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
