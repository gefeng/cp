#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return (int64_t)a * b / gcd(a, b);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::set<int> s;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        s.insert(A[i]);
    }

    std::sort(A.begin(), A.end());

    if(A.back() == A[0]) {
        std::cout << 0 << '\n';
        return;
    }
    
    for(int i = 0; i < N - 1; i++) {
        if(A.back() % A[i] != 0) {
            std::cout << N << '\n';
            return;
        }
    }

    std::vector<int> divisors;
    for(int f = 2; f * f <= A.back(); f++) {
        if(A.back() % f == 0) {
            if(s.find(f) == s.end()) {
                divisors.push_back(f);
            }
            
            if(A.back() / f != f && s.find(A.back() / f) == s.end()) {
                divisors.push_back(A.back() / f);
            }
        }
    }

    int ans = 0;
    for(int div : divisors) {
        int g = 1;
        int len = 0;
        for(int i = 0; i < N; i++) {
            if(div % A[i] == 0) {
                g = lcm(g, A[i]); 
                len += 1;
            }
        }
        if(g == div) {
            ans = std::max(ans, len);
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
