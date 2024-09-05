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
    for(int i = 0; i < N; ) {
        int j = i;
        
        int d = 0;
        while(i + 1 < N) {
            if(i == j) {
                d = A[i + 1] - A[i]; 
                i += 1;
            } else {
                if(d == A[i + 1] - A[i]) {
                    i += 1;
                } else {
                    break;
                }
            }
        }

        int len = (i - j + 1);
        ans += int64_t(len) * (len + 1) / 2;
        if(j) {
            ans -= 1;
        }
        
        if(i == N - 1) {
            break;
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
