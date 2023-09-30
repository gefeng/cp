#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int A, B, N;
    std::cin >> A >> B >> N;

    std::vector<int> C(N);
    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    std::sort(C.begin(), C.end());
    
    int64_t ans = 0;
    int64_t cur = B;
    for(int i = 0; i < N; i++) {
        ans += cur - 1;
        cur = 1;
        cur = std::min((int64_t)A, cur + C[i]);
    } 

    ans += cur;
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
