#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;

    std::vector<int> C(N);
    for(int i = 0; i < N; i++) {
        std::cin >> C[i];
    }

    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    if(A > B) {
        std::swap(A, B);
    }

    int g = gcd(A, B);

    std::sort(C.begin(), C.end());
    
    for(int i = 1; i < N; i++) {
        int k = (C[i] - C[0]) / g;
        C[i] -= k * g;
    }

    std::sort(C.begin(), C.end());
    C.erase(std::unique(C.begin(), C.end()), C.end());
     
    N = C.size();
    int ans = C.back() - C[0];
    for(int i = 1; i < N; i++) {
        int max_v = std::max(C.back() - C[i], C[i - 1] + g - C[i]);
        ans = std::min(ans, max_v);
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
