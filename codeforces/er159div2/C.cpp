#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    std::set<int64_t> s;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        s.insert(A[i]);
    }

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    std::sort(A.begin(), A.end());

    int64_t g = A[1] - A[0];
    for(int i = 2; i < N; i++) {
        g = gcd(A[i] - A[i - 1], g);
    }

    int64_t sum = 0;
    int64_t ans = 0;
    for(int i = 0; i < N - 1; i++) {
        sum += (A.back() - A[i]) / g; 
    }

    ans = sum + N;
    
    int64_t x = A.back() - g;
    while(true) {
        if(s.find(x) == s.end()) {
            ans = std::min(ans, sum + (A.back() - x) / g);
            break;
        } 
        x -= g;
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
