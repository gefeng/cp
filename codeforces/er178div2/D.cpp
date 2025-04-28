#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int MAX = 6e6;

std::vector<int> primes;
std::vector<int> is_prime;
std::vector<int64_t> psum_p;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::sort(A.begin(), A.end());
    
    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
    
    int ans = N - 1;
    for(int i = 0; i < N; i++) {
        int cnt = N - i; 
        if(sum - psum_p[cnt] >= 0) {
            ans = i; 
            break;
        }
        sum -= A[i];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    is_prime.resize(MAX + 1, 1);
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i + i; j <= MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    } 

    int size = primes.size();
    psum_p.resize(size + 1, 0);
    
    for(int i = 0; i < size; i++) {
        psum_p[i + 1] = psum_p[i] + primes[i];
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
