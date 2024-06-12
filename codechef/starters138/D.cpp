#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = (int)1e5;

std::vector<int> is_prime;
std::set<int64_t> primes;

void run_case() {
    int64_t N;
    std::cin >> N;

    if(N - 4 <= 0) {
        std::cout << "No" << '\n';
        return;
    }

    for(int64_t a : primes) {
        if(a == 4) {
            continue;
        }
        int64_t b = N - 4 - a;
        if(b > 4 && a != b && primes.find(b) != primes.end()) {
            std::cout << "Yes" << '\n';
            return;
        }
    } 

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    is_prime.resize(MAX + 1, 1);
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            primes.insert((int64_t)i * i); 
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
