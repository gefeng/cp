#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N, L, R;
    std::cin >> N >> L >> R;
    
    std::vector<int> ans(N);
    for(int i = 1; i <= N; i++) {
        int t = (L + i - 1) / i;
        if(t * i > R) {
            std::cout << "NO" << '\n';
            return;
        }
        ans[i - 1] = t * i;
    }
    
    std::cout << "YES" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
