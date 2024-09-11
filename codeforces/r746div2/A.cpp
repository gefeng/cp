#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, H;
    std::cin >> N >> H;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    int x = A[N - 1] + A[N - 2];
    int t = H / x;
    int ans = t * 2; 
    
    H -= t * x;
    if(H > 0) {
        H -= A.back();
        ans += 1;
    }
    
    if(H > 0) {
        H -= A[N - 2];
        ans += 1;
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
