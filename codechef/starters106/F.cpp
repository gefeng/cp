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

constexpr int MAX = (int)2e6;

std::vector<int> is_prime;
std::vector<int> a;

void run_case() { 
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    int x = 1;
    for(int i = 0; i < N; ) {
        while(x < A[i]) {
            if(x == 1 || is_prime[x] || a[x]) {
                std::cout << x << '\n';
                return;
            }
            x += 1;
        } 

        while(i < N && A[i] == x) {
            i += 1;
        }
        x += 1;
    }

    while(true) {
        if(is_prime[x] || a[x]) {
            std::cout << x << '\n';
            return;
        }
        
        x += 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    is_prime.resize(MAX + 1, 1);
    is_prime[1] = 0;
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    a.resize(MAX + 1, 0);
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            for(int64_t x = (int64_t)i * i, cnt = 2; x <= MAX; x *= i, cnt += 1) {
                a[x] = cnt;
            }
        }
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
