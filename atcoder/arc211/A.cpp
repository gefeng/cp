#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    std::array<int, 10> A = {};
    for(int i = 1; i < 10; i++) {
        std::cin >> A[i];
    }

    int64_t sum = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));

    if(A[5]) {
        if(A[5] == 1) {
            std::cout << 0 << '\n';
            return;
        }
        
        std::cout << std::max(static_cast<int64_t>(0), A[5] - 1 - (sum - A[5])) << '\n';
    } else {
        int pre = 0;
        int now = 0;
        for(int i = 1; i < 10; i++) {
            if(A[i]) {
                if(pre && pre + i == 10) {
                    now = i; 
                    break;
                }
                pre = i;
            }
        }

        if(now) {
            for(int i = 1; i < 10; i++) {
                if(A[i] && i != pre && i != now) {
                    std::cout << 0 << '\n';
                    return;
                }
            }      
            std::cout << 1 << '\n';
        } else {
            std::cout << 0 << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
