#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, H, W;
    std::cin >> N >> H >> W;

    if(H > W) {
        std::swap(H, W);
    }

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A); 
    
    while(!A.empty() && A.back() > W) {
        A.pop_back();
    }

    int ans = 0;
    int l = 0;
    int r = A.size() - 1;
    while(l < r && A[l] <= H) {
        ans += 1;
        l += 1;
        r -= 1;
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
