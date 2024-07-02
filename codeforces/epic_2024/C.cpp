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
    int64_t wait = 0;
    for(int i = N - 1; i >= 0; i--) {
        int64_t cnt_t = 0;
        
        if(i == N - 1) {
            cnt_t = A[i];
            wait = 0;
        } else {
            if(A[i] > A[i + 1]) {
                if(wait >= A[i] - A[i + 1]) {
                    wait = wait - (A[i] - A[i + 1]) + 1;  
                    cnt_t = wait + A[i]; 
                } else {
                    cnt_t = A[i];
                    wait = 0;
                }
            } else {
                cnt_t = wait + (A[i + 1] - A[i] + 1) + A[i];
                wait += A[i + 1] - A[i] + 1; 
            }
        }

        ans = std::max(ans, cnt_t);
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
