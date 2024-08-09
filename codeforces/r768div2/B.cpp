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

    int val = A.back();
    int size = 0;
    int ans = 0;
    for(int i = N - 1; i >= 0; ) {
        if(A[i] == val) {
            size += 1;
            i -= 1;
        } else {
            ans += 1;
            i -= size; 
            size *= 2;
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
