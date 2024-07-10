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
    for(int i = 0; i < 30; i++) {
        int have_one = false;
        for(int j = 0; j < N; j++) {
            if(A[j] & (1 << i)) {
                have_one = true;
                break;
            }
        } 

        if(!have_one) {
            for(int j = 0; j < N; j++) {
                for(int k = 29; k > i; k--) {
                    if(A[j] & (1 << k)) {
                        ans += 1;
                        break;
                    }
                }
            } 

            std::cout << ans << '\n';
            return;
        }
    }

    std::cout << 0 << '\n';
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
