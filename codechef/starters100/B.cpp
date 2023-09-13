#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = (int)1e5;

std::vector<int> is_prime;

void run_case() {
    int N;
    std::cin >> N;

    if(N == 2 || N == 3) {
        std::cout << -1 << '\n';
        return;
    }

    if(N % 2 == 0 || N < 11) {
        for(int i = 1; i <= N; i++) {
            int d = i - 1;
            if(is_prime[d] && is_prime[N - i + 1]) {
                for(int j = i; j <= N; j++) {
                    std::cout << j << " ";
                } 
                for(int j = 1; j <= i - 1; j++) {
                    std::cout << j << " ";
                }
                std::cout << '\n';
                return;
            }
        }
    } else {
        int n = N - 5;
        for(int i = 1; i <= n; i++) {
            int d = i - 1;
            if(is_prime[d] && is_prime[n - i + 1]) {
                for(int j = i; j <= n; j++) {
                    std::cout << j << " ";
                } 
                for(int j = 1; j <= i - 1; j++) {
                    std::cout << j << " ";
                }
                break;
            }
        }

        for(int i = N - 1; i <= N; i++) {
            std::cout << i << " ";
        }

        for(int i = N - 4; i <= N - 2; i++) {
            std::cout << i << " ";
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    is_prime.resize(MAX + 1, 1);
    is_prime[0] = 0;
    is_prime[1] = 0;
    for(int i = 2; i <= MAX; i++) {
        if(is_prime[i]) {
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
