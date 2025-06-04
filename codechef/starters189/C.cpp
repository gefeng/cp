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

    int ans = 0;
    for(int i = 0; i < N; i++) {
        int pre = -1;
        for(int j = i; j < N; j++) {
            if(A[j] <= pre) {
                break;
            }
            int r = (A[j] - 1) / 2;
            if(pre + 1 <= r) {
                pre++;
            } else {
                pre = A[j];
            }
            ans += 1;
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
