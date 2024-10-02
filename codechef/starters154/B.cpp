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
    
    if(N == 1) {
        std::cout << A[0] << '\n';
        return;
    }

    int64_t ans = int64_t(N) * (N + 1) / 2;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i + 1 < N && (A[i + 1] == 0 || A[i + 1] != A[i])) {
            if(i - j > 0 && A[i + 1] == A[i - 1] && A[i - 1] == 1) {
                break;
            }
            i += 1;
        }

        int64_t len = i - j + 1;
        if(len > 1) {
            ans -= len * (len + 1) / 2; 
            for(int k = j; k <= i; k++) {
                if(A[k] == 1) {
                    ans += 1;
                } 
            }

            if(j > 0 && A[j] == 0) {
                ans += 1;
            }
        } else {
            i += 1;
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
