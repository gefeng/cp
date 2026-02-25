#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    int min_v = INF;
    for(int i = 0; i < N; i++) {
        min_v = A[i];
        ans += 1;
        while(i + 1 < N) {
            if(A[i + 1] <= min_v) {
                break;
            }
            if((A[i + 1] - 1 == A[i]) || A[i + 1] <= A[i]) {
                i += 1;
            } else {
                break;
            }
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
