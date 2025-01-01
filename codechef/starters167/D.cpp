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
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t ans = 0;
    std::vector<int64_t> s;
    for(int i = 0; i < N; i++) {
        if(A[i] == 0) {
            continue;
        }

        if(s.empty()) {
            s.push_back(i);
            continue;
        }
        
        while(!s.empty() && ((A[s.back()] < 0 && A[i] > 0) || (A[s.back()] > 0 && A[i] < 0))) {
            if(std::abs(A[s.back()]) == std::abs(A[i])) {
                ans += std::abs(A[i]) * (i - s.back());
                A[i] = 0;
                s.pop_back();
                break;
            }

            if(std::abs(A[i]) > std::abs(A[s.back()])) {
                ans += std::abs(A[s.back()]) * (i - s.back());
                A[i] += A[s.back()];
                s.pop_back();
                continue;
            }

            ans += std::abs(A[i]) * (i - s.back());
            A[s.back()] += A[i];
            A[i] = 0;
            break;
        }
        
        if(A[i] != 0) {
            s.push_back(i);
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
