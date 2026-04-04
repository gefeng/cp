#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 2e5;

std::vector<int64_t> is_primes;
std::vector<int64_t> primes;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> ans(N, 0);
    ans[0] = 1;
    ans[1] = 2; 
    for(int i = 2, j = 0; i < N; i++, j++) {
        ans[i] = primes[j] * primes[j + 1];
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    is_primes.resize(MAX + 1, 1);
    for(int i = 2; i <= MAX; i++) {
        if(is_primes[i]) {
            primes.push_back(i);
            for(int j = i + i; j <= MAX; j += i) {
                is_primes[j] = 0;
            }
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
