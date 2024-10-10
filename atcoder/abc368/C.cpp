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

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0; 
    for(int i = 0; i < N; i++) {
        while(ans % 3 != 0 && A[i] > 0) {
            ans += 1;
            if(ans % 3 == 0) {
                A[i] -= 3;
            } else {
                A[i] -= 1;
            }
        }

        if(A[i] == 0) {
            continue;
        }

        int64_t t = A[i] / 5;
        A[i] -= 5 * t;
        ans += t * 3;
        
        while(A[i] > 0) {
            ans += 1;
            if(ans % 3 == 0) {
                A[i] -= 3;
            } else {
                A[i] -= 1;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
