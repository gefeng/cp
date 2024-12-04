#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto ceil = [&](int x) {
        if(x >= 0) {
            return (x + K - 1) / K;
        }
        return -(-x / K);
    };

    auto floor = [&](int x) {
        if(x >= 0) {
            return x / K;
        }
        return -((-x + K - 1) / K);
    };

    int64_t sum = 0;
    for(int x : A) {
        sum += floor(x);
    }
    
    if(sum == 0) {
        std::cout << "YES" << '\n';
        return;
    }
    if(sum > 0) {
        std::cout << "NO" << '\n';
        return;
    }

    for(int x : A) {
        if(x % K != 0 && sum < 0) {
            sum += ceil(x) - floor(x); 
        }
    }

    std::cout << (sum == 0 ? "YES" : "NO") << '\n';
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
