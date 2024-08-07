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
    int t = 0;
    while(true) {
        bool end = true;
        for(int i = 1; i < N; i++) {
            if(A[i] < A[i - 1]) {
                end = false;
                break;
            }
        }

        if(end) {
            break;
        }
        
        for(int i = t; i < N; i += 2) {
            if(t == 0) {
                if(i + 1 < N && A[i] > A[i + 1]) {
                    std::swap(A[i], A[i + 1]);
                }
            } else {
                if(i + 1 < N && A[i] > A[i + 1]) {
                    std::swap(A[i], A[i + 1]);
                }
            }
        }

        ans += 1;
        t ^= 1;
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
