#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> divisors; 
    std::vector<int> ans; // save answer for each divisors of M
    for(int f = 1; f * f <= M; f++) {
        if(M % f == 0) {
            divisors.push_back(f);
            if(M / f != f) {
                divisors.push_back(M / f);
            }
        }
    }

    std::ranges::sort(divisors);
    ans.resize(std::size(divisors), 0);

    for(int i = 0; i < std::size(divisors); i++) {
        for(int j = 0; j < N; j++) {
            if(j && A[j] % divisors[i] < A[j - 1] % divisors[i]) {
                ans[i] += 1;
            }
        }
    }

    auto update = [&](int p, int x) {
        if(A[p] == x) {
            return;
        }
        
        for(int i = 0; i < std::size(divisors); i++) {
            if(p && A[p] % divisors[i] < A[p - 1] % divisors[i]) {
                ans[i] -= 1;
            }
            if(p + 1 < N && A[p + 1] % divisors[i] < A[p] % divisors[i]) {
                ans[i] -= 1;
            }

            if(p && x % divisors[i] < A[p - 1] % divisors[i]) {
                ans[i] += 1;
            }
            if(p + 1 < N && A[p + 1] % divisors[i] < x % divisors[i]) {
                ans[i] += 1;
            }
        }
        A[p] = x;
    };

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;
        
        if(T == 1) {
            int P, X;
            std::cin >> P >> X;
            P -= 1;
            update(P, X);
        } else {
            int K;
            std::cin >> K;
        
            int g = gcd(K, M);
            std::cout << (ans[std::ranges::lower_bound(divisors, g) - divisors.begin()] <= M / g - 1 ? "Yes" : "No") << '\n';
        }
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
