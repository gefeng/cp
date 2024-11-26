#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::set<int> s;
    for(int i = 1; i < N; i++) {
        s.insert(A[i] - A[i - 1]); 
    }

    if(s.size() > 2) {
        std::cout << -1 << '\n';
        return;
    }

    if(s.size() == 1) {
        std::cout << 0 << '\n';
        return;
    }

    int x = *s.begin();
    int y = *s.rbegin();

    if(int64_t(x) * y >= 0) {
        std::cout << -1 << '\n';
        return;
    }

    int64_t m = std::abs(x) + y;
    int64_t c = m + x;
    if(A[0] >= m || c < 0 || c >= m) {
        std::cout << -1 << '\n';
        return;
    }

    for(int i = 1; i < N; i++) {
        if(A[i] != (c + A[i - 1]) % m) {
            std::cout << -1 << '\n';
            return;
        }
    }

    std::cout << m << ' ' << c << '\n';
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
