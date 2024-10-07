#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e7);

std::vector<int> is_prime(MAX + 1, 1);
std::vector<int> primes;
std::vector<int> all;

void run_case(int T) {
    int N;
    std::cin >> N;

    auto it = std::upper_bound(all.begin(), all.end(), N - 2);

    std::cout << "Case #" << T << ": " << (N < 5 ? 0 : it - all.begin()) << '\n';
}

int main() {
    int T;
    std::cin >> T;

    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    int n = primes.size();
    all.push_back(2);
    for(int i = 1; i < n; i++) {
        if(primes[i] + 2 <= MAX && is_prime[primes[i] + 2]) {
            all.push_back(primes[i]); 
        }
    }
    
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
