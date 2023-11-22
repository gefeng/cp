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
    int sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum ^= A[i];
    }

    int ans = sum;
    for(int i = 0; i < N; i++) {
        ans = std::min(ans, sum ^ A[i]); 
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
