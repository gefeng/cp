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
    
    std::vector<std::array<int64_t, 2>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i][0];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i][1];
    }

    std::sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
                if(a[0] * b[1] == a[1] * b[0]) {
                    return a[0] < b[0];
                }
                return a[0] * b[1] < a[1] * b[0];
            });

    int ans = N;
    int max_p = -1;
    for(int i = 0; i < N; i++) {
        if(max_p > A[i][0]) {
            ans -= 1;
        }
        max_p = std::max(max_p, int(A[i][0]));
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
