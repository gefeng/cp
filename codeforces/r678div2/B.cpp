#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e5);

std::vector<int> primes;
std::vector<int> is_prime;

void run_case() {
    int N;
    std::cin >> N;
    
    int p = std::lower_bound(primes.begin(), primes.end(), N) - primes.begin();
    
    std::vector<std::vector<int>> ans(N, std::vector<int>(N, 1));
    for(int i = p; i < primes.size(); i++) {
        int x = primes[i];
        
        if(!is_prime[x - N + 1]) {
            for(int j = 0; j < N; j++) {
                ans[j][j] = x - N + 1;
            } 
            break;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << ans[i][j] << " \n"[j == N - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    is_prime.resize(MAX + 1, 1); 
    is_prime[1] = 0;
    is_prime[0] = 0;
    
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
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
