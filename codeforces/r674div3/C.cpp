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

    int ans = N - 1;
    
    int n = static_cast<int>(sqrt(N));
    
    for(int i = n - 1; i <= n + 1; i++) {
        if(i >= 1) {
            ans = std::min(ans, i - 1 + (N - 1) / i);
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
