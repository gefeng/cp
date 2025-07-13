#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <random>
#include <chrono>

int gcd(int a, int b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N, M, P;
    std::cin >> N >> M >> P;
    
    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(gcd(A[i], P) == 1) {
            ans += i;
            break;
        }
    }

    for(int i = 0; i < M; i++) {
        if(gcd(B[i], P) == 1) {
            ans += i;
            break;
        }
    } 

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
