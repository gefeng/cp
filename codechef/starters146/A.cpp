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
    int64_t sum = 0; 
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    int ans = 0;
    int64_t now = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] != 0) {
            now += A[i];
        } else {
            if(now == sum - now) {
                ans += 2;
            } else {
                if(std::abs(now - sum + now) == 1) {
                    ans += 1;
                }
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
