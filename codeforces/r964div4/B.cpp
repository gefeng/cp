#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 2> A;
    std::array<int, 2> B;

    for(int i = 0; i < 2; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < 2; i++) {
        std::cin >> B[i];
    }

    int ans = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            int cnt_1 = 0;
            int cnt_2 = 0;
            if(A[i] > B[j]) {
                cnt_1 += 1; 
            } else if(B[j] > A[i]) {
                cnt_2 += 1;
            }

            if(A[i ^ 1] > B[j ^ 1]) {
                cnt_1 += 1;
            } else if(A[i ^ 1] < B[j ^ 1]) {
                cnt_2 += 1;
            }

            if(cnt_1 > cnt_2) {
                ans += 1;
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
