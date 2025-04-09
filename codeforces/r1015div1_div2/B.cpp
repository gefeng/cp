#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    if(A[0] == A.back()) {
        std::cout << "Yes" << '\n';
        return;
    }
    
    if(A[1] == A[0]) {
        std::cout << "Yes" << '\n';
        return;
    }

    std::vector<int64_t> a;
    for(int i = 1; i < N; i++) {
        if(A[i] % A[0] == 0) {
            a.push_back(A[i] / A[0]);
        } 
    }

    int size = a.size();
    if(size < 2) {
        std::cout << "No" << '\n';
        return;
    }

    int64_t g = a[0];
    for(int i = 1; i < size; i++) {
        g = gcd(g, a[i]);
    } 

    std::cout << (g == 1 ? "Yes" : "No") << '\n';
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
